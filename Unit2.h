//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TEdit *Edit1;
	TEdit *Edit2;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Image4MouseEnter(TObject *Sender);
	void __fastcall Image4MouseLeave(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
