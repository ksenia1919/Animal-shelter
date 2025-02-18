//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image2;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TImage *Image3;
	TEdit *Edit5;
	void __fastcall Image2MouseEnter(TObject *Sender);
	void __fastcall Image2MouseLeave(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image3MouseEnter(TObject *Sender);
	void __fastcall Image3MouseLeave(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
