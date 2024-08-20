//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3* Form3;
int Num_Animal = 0;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormClose(TObject* Sender, TCloseAction &Action)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image2MouseEnter(TObject *Sender)
{
	Image2->Picture->LoadFromFile("Figma_dounlad\\Птицы_клик.png");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image2MouseLeave(TObject *Sender)
{
	Image2->Picture->LoadFromFile("Figma_dounlad\\Птицы.png");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image2Click(TObject *Sender)
{
	MediaPlayer1->FileName ="Music\\Птички.wav";
	MediaPlayer1->Open();
	MediaPlayer1->Play();
	/////
	Num_Animal = 1;
	Form5->Show();
	Form3->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image3MouseEnter(TObject *Sender)
{
	Image3->Picture->LoadFromFile("Figma_dounlad\\Собаки_клик.png");

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image3MouseLeave(TObject *Sender)
{
	Image3->Picture->LoadFromFile("Figma_dounlad\\Собаки.png");

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image3Click(TObject *Sender)
{
	MediaPlayer1->FileName ="Music\\Собачка.wav";
	MediaPlayer1->Open();
	MediaPlayer1->Play();
	/////
	Num_Animal = 2;
	Form5->Show();
	Form3->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image4MouseEnter(TObject *Sender)
{
	Image4->Picture->LoadFromFile("Figma_dounlad\\Коты_клик.png");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image4MouseLeave(TObject *Sender)
{
	Image4->Picture->LoadFromFile("Figma_dounlad\\Коты.png");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image4Click(TObject *Sender)
{
	MediaPlayer1->FileName ="Music\\Котик.wav";
	MediaPlayer1->Open();
	MediaPlayer1->Play();
    /////
	Num_Animal = 3;
	Form5->Show();
	Form3->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::PutMouseEnter(TObject *Sender)
{
	Image5->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::PutMouseLeave(TObject *Sender)
{
    Image5->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::PutClick(TObject *Sender)
{
    Form2->Show();
	Form3->Hide();
}
//---------------------------------------------------------------------------


