//---------------------------------------------------------------------------
 #include <jpeg.hpp>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
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
	Image2->Picture->LoadFromFile("A_Button_registr_Klik.jpg");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2MouseLeave(TObject *Sender)
{
	Image2->Picture->LoadFromFile("A_Button_registr_Active.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
   ADOQuery1->SQL->Text = "Select * from Users";
   ADOQuery1->Active = true;
   Edit5->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
    if(Edit1->Text == "" && Edit2->Text == "" && Edit3->Text == "" && Edit4->Text == "" && Edit5->Text == "")
	{
		Application->Title="��������!";
		ShowMessage("��� ����������� ��������� ��������� ��� ����.");
	}
	else
	{
	int count_registr = 0;
	///Edit1
	if(Edit1->Text != "")
	{
		count_registr++;
	}
	else
	{
		Application->Title="��������!";
		ShowMessage("����������, ������� ���� ���.");
	}
	///Edit2
	if(Edit2->Text != "")
	{
		if(Edit2->Text.Pos('@')!=0){
		count_registr++;
		}
		else
		{
			Application->Title="������!";
			ShowMessage("�-mail ������ ����������.");
		}
	}
	else
	{
		Application->Title="��������!";
		ShowMessage("����������, ������� ��� E-mail.");
	}
	///Edit3
	if(Edit3->Text != "")
	{
		TLocateOptions options;
		if (ADOQuery1->Locate("�����", Edit3->Text, options))
		{
		   ShowMessage("����� ��� ��� ����� ������ �������������.");
		}
		else count_registr++;
	}
	else
	{
		Application->Title="��������!";
		ShowMessage("����������, ������� �����.");
	}
	///Edit4
	if(Edit4->Text != "")
	{
		if(Edit4->Text.Length() < 7)
		{
			Application->Title="��������!";
			ShowMessage("����������, ������� ������, ���������� �� ����� 7 ��������.");
		}
		else {count_registr++;}
	}
	else
	{
		Application->Title="��������!";
		ShowMessage("����������, ������� ������.");
	}
	///Edit5
	if(Edit5->Text != "")
	{
		if(Edit4->Text == Edit5->Text) {
		count_registr++;
		}
		else
		{
			Application->Title="������!";
			ShowMessage("������ �� ���������.");
		}
	}
	else
	{
		Application->Title="��������!";
		ShowMessage("����������, ��������� ���� ������.");
	}

	if(Edit1->Text != "" && Edit2->Text != "" && Edit3->Text != "" && Edit4->Text != "" && Edit5->Text != "" ) {
		if(count_registr == 5)
		{
			ADOQuery1->Insert();
			ADOQuery1->Fields->FieldByName("���")->AsString = Edit1->Text;
			ADOQuery1->Fields->FieldByName("�����")->AsString = Edit2->Text;
			ADOQuery1->Fields->FieldByName("�����")->AsString = Edit3->Text;
			ADOQuery1->Fields->FieldByName("������")->AsString = Edit4->Text;
			ADOQuery1->Fields->FieldByName("��� ������������")->AsString = "������������";
			ADOQuery1->Post();
			Form2->Show();
			Form1->Hide();
			count_registr = 0;
		}
	}
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image3MouseEnter(TObject *Sender)
{
	Image3->Picture->LoadFromFile("afterButton_registr_Klik.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseLeave(TObject *Sender)
{
	Image3->Picture->LoadFromFile("afterButton_registr_Active.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
    Form2->Show();
	Form1->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
 if(Key == '_' ||Key == '.' ||Key == ',' ||Key == '?' ||Key == '!' ||Key == '>' ||Key == '<' ||Key == '/' || Key == '0' ||Key == '1' ||Key == '2' ||Key == '3' ||Key == '4' ||Key == '5' ||Key == '6' ||Key == '7' ||Key == '8' ||Key == '9'){
 Key = 0;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{
	WideChar key = towlower(Key);
	if((key<'a' || key>'z') && key != '_'  && key != '.' && !isdigit(key) && !(Key == VK_BACK) ){
	Key = 0;
	}
}
//---------------------------------------------------------------------------


