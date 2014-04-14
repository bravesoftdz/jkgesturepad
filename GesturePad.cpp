//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GesturePad.h"
#include "Settings.h"
#include <RegularExpressions.hpp>
#include <algorithm>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGesturePad *frmGesturePad;
//---------------------------------------------------------------------------
__fastcall TfrmGesturePad::TfrmGesturePad(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmGesturePad::actGesture(TObject *Sender)
{
   //do some quick finalizations
   dFinal = d;
   vFinal = vtemp2;
   aFinal = a;

   pointStart = pointa;
   pointFinal = pointb;

   TAction* cur = dynamic_cast<TAction*>(Sender);
   String s;
   try {
	 s = TRegEx::Match(cur->Name, "\\d+", TRegExOptions() << roIgnoreCase << roMultiLine).Value;
   } catch (ERegularExpressionError *ex) {
	  return;	// Syntax error in the regular expression
   }
   int item = StrToIntDef(s, 0)-1;
   String sItem = "";
   int param_split = 0;
   bool exists = false, isurl = false;
   int cmd_ran_count = 0, cmd_fail_count = 0;
   String wholecmd, file, params;
   if (item >= 0) {
	   sItem = frmSettings->cmbGesture->Items->Strings[item];
	   lstDebug->Items->Add(sItem);
	   TListBox* lst = frmSettings->lstGestureCmds;
	   for (int i = 0; i <lst->Count;i++) {
		   s = lst->Items->Strings[i];
		   if (s.Pos(sItem) == 1){

				params = "";
				exists = false;
				file = s.SubString(sItem.Length()+1,s.Length()).Trim();
				wholecmd = file;
				isurl = wholecmd.Pos("http://") == 1 || wholecmd.Pos("https://") == 1;
				param_split = file.Length();

				while(file.Length()>3){
				  if (FileExists(file)){
					 exists = true;
					 break;
				  }
				  file = file.SubString(0, --param_split);
				}
				Debug(wholecmd + " exists: " + (exists ? "1 ":"0 ") +
							   "isurl: "+(isurl ? "1 " : "0 "));
				if (!exists && !isurl) {
					//TODO: LOG that file does not exists
					Debug(file+" does not exist");
					cmd_fail_count++;
					continue;
				}

				if (!isurl && file.Length() < wholecmd.Length()){

				   params = wholecmd.SubString(param_split, wholecmd.Length());
				   Debug("params: " + params);
				   if (params.Length() >= 3){ params = StringReplace(params,"%d%", dFinal,TReplaceFlags() << rfReplaceAll); }
				   if (params.Length() >= 3){ params = StringReplace(params,"%v%", vFinal,TReplaceFlags() << rfReplaceAll); }
				   if (params.Length() >= 3){ params = StringReplace(params,"%a%", aFinal,TReplaceFlags() << rfReplaceAll); }
				   if (params.Length() >= 4){ params = StringReplace(params,"%sx%", pointStart.x,TReplaceFlags() << rfReplaceAll); }
				   if (params.Length() >= 4){ params = StringReplace(params,"%sy%", pointStart.y,TReplaceFlags() << rfReplaceAll); }
				   if (params.Length() >= 4){ params = StringReplace(params,"%fx%", pointFinal.x,TReplaceFlags() << rfReplaceAll); }
				   if (params.Length() >= 4){ params = StringReplace(params,"%fy%", pointFinal.y,TReplaceFlags() << rfReplaceAll); }
				   Debug("params: " + params);
				}

				if (isurl) {
                    file = wholecmd;
				}
                Hide();
				ShellExecute(NULL,
							String("open").w_str(),
							file.w_str(),
							params.w_str(), // params
							String(" C:\\ ").w_str(),
							SW_SHOW);
				cmd_ran_count++;
		   }
	   }
   }
   if (cmd_fail_count) {
		 Debug(IntToStr(cmd_ran_count)+ "/" +
						  IntToStr(cmd_ran_count+cmd_fail_count) + " executed.");
   }
   lbl1->Caption = sItem;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGesturePad::Settings1Click(TObject *Sender)
{
	frmSettings->Show();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGesturePad::Debug(const String& s){
  lstDebug->Items->Add(s);
  lstDebug->ScrollBy(0,10);
  lstDebug->Perform(EM_SCROLLCARET, 0, 0);

   int yPos = lstDebug->Height;
   int yMax = lstDebug->Height*2;
   int yInc = lstDebug->Font->Height*2;
   /*
	* Increment the scrolling position, adjust the position
	* of the thumb, and update the window.
	*/
	if (yInc = std::max (-yPos, std::min (yInc, yMax - yPos))) {
		yPos += yInc;
		ScrollWindow (lstDebug->Handle, -lstDebug->Font->Height * yInc, 0,
		(CONST RECT *) NULL, (CONST RECT *) NULL);
		SetScrollPos (lstDebug->Handle, SB_VERT, yPos, TRUE);
		UpdateWindow (lstDebug->Handle);
	}
	lstDebug->Refresh();
}

void __fastcall TfrmGesturePad::FormCreate(TObject *Sender)
{

	//find User Dir ie. c:/Users/JimKinsman
	if (UserDir.Length() == 0){

				PWSTR user_dir = 0;
				if (SUCCEEDED(SHGetKnownFolderPath(
									FOLDERID_Profile,
									0,
									NULL,
									&user_dir)))
				{
					   UserDir = String(user_dir);
					   CoTaskMemFree(user_dir);
				}
		 ConfigFile = UserDir+"/JKGestureCmds.cfg";
	 }else{
         ConfigFile = ExtractFilePath(Application->ExeName)+"/JKGestureCmds.cfg";
     }

	 pointa.x = -1;
	 vtemp = -1;
	 sw = new TStopwatch();
	 sw2 = new TStopwatch();
}
//---------------------------------------------------------------------------


void __fastcall TfrmGesturePad::Exit1Click(TObject *Sender)
{
   Exit = true;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGesturePad::TrayIcon1Click(TObject *Sender)
{
   Show();
   Application->RestoreTopMosts();
   ShowWindow(this->Handle, SW_RESTORE);
}
//---------------------------------------------------------------------------

void __fastcall TfrmGesturePad::FormPaint(TObject *Sender)
{
	ShowWindow(Application->Handle, SW_HIDE);
	if (FileExists(ConfigFile)) {
	   frmSettings->lstGestureCmds->Items->LoadFromFile(ConfigFile);
   }
	this->OnPaint = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGesturePad::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   CanClose = Exit;
   if (!CanClose) {
      Hide();
   }
}
//---------------------------------------------------------------------------
int __fastcall TfrmGesturePad::Displacement(tagPOINT* q, tagPOINT* p){
   int rx = q->x - p->x;
   int ry = q->y - p->y;
   double d = sqrt(rx*rx + ry*ry) + 0.5;
   return (int)d;
}

//---------------------------------------------------------------------------

void __fastcall TfrmGesturePad::FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if (!(Shift.Contains(ssTouch) || Shift.Contains(ssLeft))) {
	   if (pointa.x != -1) {
	       dFinal = d;
		   vFinal = vtemp2;
		   aFinal = a;

		   pointStart = pointa;
		   pointFinal = pointb;
		   pointa.x = -1;
		   Debug("Done touching..Accel: "+FloatToStr(a)+" Velocity: "+vtemp2);
		   vtemp = -1;
		   lstDebug->Refresh();
	   }
	   return;
	}

	if (pointa.x == -1){
		vtemp = -1;
		GetCursorPos(&pointa);
		sw->Reset();
		sw->Start();
		t = 0;
	}else{
		t2 = sw->Elapsed.TotalMilliseconds;
		t3 = t2 - t;
		if (t3 == 0) {
		   return;
		}

		GetCursorPos(&pointb);
		d = Displacement(&pointa,&pointb);
		if (vtemp == -1){
		   vtemp = 1.0*d/t3;
		}else{
			vtemp2 = (double)d/t3;
			dv = vtemp2 - vtemp;
			a = dv / t3;
		}
		Debug(IntToStr(t3)+" t, " + IntToStr(d) + " d, "
		   + FloatToStr(vtemp2) + " v, " + FloatToStr(dv) + " dv");
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmGesturePad::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete sw;
	delete sw2;
}
//---------------------------------------------------------------------------

