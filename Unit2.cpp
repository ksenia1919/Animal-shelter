//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	Form1->Close();
}
//---------------------------------------------------------------------------

int clik = 0;
void __fastcall TForm2::Image2Click(TObject *Sender)
{

	if(clik == 0){
	Edit2->PasswordChar = false;
	Image2->Picture->LoadFromFile("eye_close.jpg");
	clik++;
	}
	else
	{
	Edit2->PasswordChar = 42; // 42 ��� ����� ������� � �������
	Image2->Picture->LoadFromFile("eye_open.jpg");
	clik--;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image4Click(TObject *Sender)
{
	ADOQuery1->Active = false;
	ADOQuery1->Active = true;
	int counter_avtiriz = 0;
	//�������� ������
	if(Edit1->Text!= "")
	{
		TLocateOptions options;
		if (ADOQuery1->Locate("�����", Edit1->Text, options))
		{
			counter_avtiriz++;
		}
		else
		{
			Application->Title="�������!";
			ShowMessage("����� �� ��� ������(");
		}
	}
	else if(Edit1->Text == "" && Edit2->Text != "")
	{
	Application->Title="��������!";
	ShowMessage("����������, ������� �����.");
	}
	//�������� ������
	if(Edit2->Text!= "")
	{
		TLocateOptions options;
		if (ADOQuery1->Locate("������", Edit2->Text, options))
		{
			counter_avtiriz++;
		}
		else
		{
			Application->Title="�������!";
			ShowMessage("������ � ����� �� ���������");
		}
	}
	else if(Edit1->Text != "" && Edit2->Text == "")
	{
	Application->Title="��������!";
	ShowMessage("����������, ������� ������.");
	}
	//�����������
	if(Edit1->Text!= "" && Edit2->Text!= "") {
		if(counter_avtiriz == 2)
		{
			//���� � ������� ������������ ��� ������������ = ������������� ��...
			TLocateOptions options;
			ADOQuery1->Locate("�����", Edit1->Text, options);
			if(ADOQuery1->FieldByName("��� ������������")->AsString == "�������������"){
            Application->Title="�����";
			ShowMessage("�� ������� �����!");
			Form4->Show();
			Form2->Hide();
			}
			else
			{
			Application->Title="�����";
			ShowMessage("�� ������� �����!");
			Form3->Show();
			Form2->Hide();
			}
		}
	}
	else if( Edit1->Text == "" && Edit2->Text == "")
	{
    Application->Title="��������!";
	ShowMessage("����������, ������� ����� � ������.");
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image4MouseEnter(TObject *Sender)
{
	Image4->Picture->LoadFromFile("Butto_vhod_Klik.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image4MouseLeave(TObject *Sender)
{
	Image4->Picture->LoadFromFile("Butto_vhod_Active.jpg");
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image3Click(TObject *Sender)
{
	Form1->Show();
	Form2->Hide();
}
//---------------------------------------------------------------------------

