//---------------------------------------------------------------------------

#ifndef SettingsH
#define SettingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmSettings : public TForm
{
__published:	// IDE-managed Components
	TListBox *lstGestureCmds;
	TLabel *Label2;
	TComboBox *cmbGesture;
	TLabel *Label3;
	TEdit *edtRunCmd;
	TSpeedButton *btnOpen;
	TPopupMenu *popGestureCmds;
	TMenuItem *Delete1;
	TOpenDialog *dlgOpen;
	void __fastcall edtRunCmdKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Delete1Click(TObject *Sender);
	void __fastcall btnOpenClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfrmSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSettings *frmSettings;
//---------------------------------------------------------------------------
#endif
