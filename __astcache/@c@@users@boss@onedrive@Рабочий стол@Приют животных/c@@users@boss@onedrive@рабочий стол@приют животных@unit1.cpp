//---------------------------------------------------------------------------
 #include <jpeg.hpp>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2MouseEnter(TObject *Sender)
{
	Image2->Picture->LoadFromFile("BUTTON_2.jpeg");
}
//---------------------------------------------------------------------------
