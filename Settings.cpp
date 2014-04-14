//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Settings.h"
#include "GesturePad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSettings *frmSettings;
//---------------------------------------------------------------------------
__fastcall TfrmSettings::TfrmSettings(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSettings::edtRunCmdKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {
		 lstGestureCmds->Items->Add(cmbGesture->Text + " " + edtRunCmd->Text);
		 if (frmGesturePad->ConfigFile.Length() > 0) {
			 lstGestureCmds->Items->SaveToFile(frmGesturePad->ConfigFile);
		 }
		 edtRunCmd->Clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::Delete1Click(TObject *Sender)
{
	lstGestureCmds->DeleteSelected();
	if (frmGesturePad->ConfigFile.Length() > 0) {
			 lstGestureCmds->Items->SaveToFile(frmGesturePad->ConfigFile);
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmSettings::btnOpenClick(TObject *Sender)
{
	if (dlgOpen->Execute()) {
	   edtRunCmd->Text = dlgOpen->FileName;
	}
}
//---------------------------------------------------------------------------

