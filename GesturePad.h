//---------------------------------------------------------------------------

#ifndef GesturePadH
#define GesturePadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Touch.GestureMgr.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <System.Diagnostics.hpp>
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
class TfrmGesturePad : public TForm
{
__published:	// IDE-managed Components
	TGestureManager *GestureManager1;
	TActionList *ActionList1;
	TAction *Action1;
	TAction *Action2;
	TAction *Action3;
	TAction *Action4;
	TAction *Action5;
	TAction *Action6;
	TAction *Action7;
	TAction *Action8;
	TAction *Action9;
	TAction *Action10;
	TAction *Action11;
	TAction *Action12;
	TAction *Action13;
	TAction *Action14;
	TAction *Action15;
	TAction *Action16;
	TAction *Action17;
	TAction *Action18;
	TAction *Action19;
	TAction *Action20;
	TAction *Action21;
	TAction *Action22;
	TAction *Action23;
	TAction *Action24;
	TAction *Action25;
	TAction *Action26;
	TAction *Action27;
	TAction *Action28;
	TAction *Action29;
	TAction *Action30;
	TAction *Action31;
	TAction *Action32;
	TAction *Action33;
	TAction *Action34;
	TLabel *lbl1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Settings1;
	TMenuItem *Exit1;
	TListBox *lstDebug;
	TImageList *ImageList1;
	TTrayIcon *TrayIcon1;
	TPopupMenu *popTray;
	TMenuItem *Settings2;
	TMenuItem *Exit2;
	TMenuItem *GesturePad1;
	TAction *Action35;
	TAction *Action36;
	TAction *Action37;
	TAction *Action38;
	TAction *Action39;
	TAction *Action40;
	TAction *Action41;
	TTimer *Timer1;
	void __fastcall Debug(const String& s);
	void __fastcall actGesture(TObject *Sender);
	void __fastcall Settings1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall TrayIcon1Click(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);

private:	// User declarations
public:		// User declarations
	String UserDir;
	String ConfigFile;
	bool Exit;
	tagPOINT pointa;
	tagPOINT pointb;
	TStopwatch* sw;
	TStopwatch* sw2;
	__int64 t;
	__int64 t2;
	__int64 t3;
	double v;
	double vtemp;
	double vtemp2;
	double dv;
	double a;
	int d;

	//final values
	int dFinal;
	double vFinal;
	double aFinal;
	tagPOINT pointStart;
	tagPOINT pointFinal;

	int __fastcall Displacement(tagPOINT* q, tagPOINT* p);
	__fastcall TfrmGesturePad(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGesturePad *frmGesturePad;
//---------------------------------------------------------------------------
#endif
