//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include <cstring>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
int col_counter = 0;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{

	int counter_admin = 0;
	///Edit1
	if(Edit1->Text != "")
	{
		counter_admin++;
	}

	///Edit2
	if(Edit2->Text != "")
	{
		if(Edit2->Text.Pos('@')!=0){
		counter_admin++;
		}
	}

	///Edit3
	if(Edit3->Text != "")
	{
		TLocateOptions options;
		if (ADOQuery1->Locate("Логин", Edit3->Text, options))
		{
		   ShowMessage("Логин уже был занят другим пользователем.");
		}
		else counter_admin++;
	}


	///Edit4
	if(Edit4->Text != "")
	{
		if(Edit4->Text.Length() < 7)
		{
			Application->Title="Внимание!";
			ShowMessage("Пожалуйста, введите пароль содержащий не менее 7 символов.");
		}
		else {counter_admin++;}
	}
	////////////////////////////////////////////
	if(Edit1->Text != "" && Edit2->Text != "" && Edit3->Text != "" && Edit4->Text != "") {
		if(counter_admin == 4)
		{
			Application->Title="Успешно!";
			ShowMessage("Данные успешно занесены в БД.");
			ADOQuery1->Insert();
			ADOQuery1->Fields->FieldByName("ФИО")->AsString = Edit1->Text;
			ADOQuery1->Fields->FieldByName("Почта")->AsString = Edit2->Text;
			ADOQuery1->Fields->FieldByName("Логин")->AsString = Edit3->Text;
			ADOQuery1->Fields->FieldByName("Пароль")->AsString = Edit4->Text;
			ADOQuery1->Fields->FieldByName("Тип пользователя")->AsString = "Администратор";
			ADOQuery1->Post();
			counter_admin = 0;

		}
        else
		{
			Application->Title="Внимание!";
			ShowMessage("Данные введены некорректно, пожалуйста перепроверьте.");
			counter_admin = 0;
		}
	}
	else
	{
		Application->Title="Внимание!";
		ShowMessage("Требуется заполнить все поля.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	//сортировка админов
	ADOQuery1->Active = False;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text="SELECT * FROM Users WHERE [Тип пользователя] = 'Администратор'";
	ADOQuery1->Active = True;
	//

	Edit1->Visible =true;
	Edit2->Visible =true;
	Edit3->Visible =true;
	Edit4->Visible =true;
	Button2->Visible = true;
	Button3->Visible =true;
	Button7->Visible =true;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{
	WideChar key = towlower(Key);
	if((key<'a' || key>'z') && key != '_'  && key != '.' && !isdigit(key) && !(Key == VK_BACK) ){
	Key = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
 if(Key == '*' || Key == '+' || Key == '=' || Key == '-' || Key == '/' || Key == '_' ||Key == '.' ||Key == ',' ||Key == '?' ||Key == '!' ||Key == '>' ||Key == '<' ||Key == '/' || Key == '0' ||Key == '1' ||Key == '2' ||Key == '3' ||Key == '4' ||Key == '5' ||Key == '6' ||Key == '7' ||Key == '8' ||Key == '9'){
 Key = 0;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button3Click(TObject *Sender)
{
if(Edit1->Text != "" && Edit2->Text != "" && Edit3->Text != "" && Edit4->Text != ""){
	//удалить пользователя из бд
	UnicodeString msg,ttl;
	msg = "Вы уверены, что хотите удалить этого администратора?";
	ttl = "Подтверждение";
	if(Application->MessageBox(msg.c_str(),ttl.c_str(),MB_YESNO) == IDYES)
	{
		//удалить данные
		ADOQuery1->Active=False;
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("SELECT ФИО FROM Users WHERE ФИО = :name");
		ADOQuery1->Parameters->ParamByName("name")->Value = Edit1->Text;
		ADOQuery1->Active=True;

		if (!ADOQuery1->RecordCount){
			 Application->Title="Ошибка!";
			 ShowMessage ("Такого аккаунта с этими данными не существует.");
			 Edit1->Clear();
			 Edit2->Clear();
			 Edit3->Clear();
			 Edit4->Clear();
			 Edit1->SetFocus();
		}
		else {
			if(Edit3->Text == "limonka"){
			Application->Title="Ошибка!";
			ShowMessage("Вы не можете удалить данного администратора.");
			}
			else{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("delete from Users where ФИО=:FIO and Почта=:Email and Логин=:Login and Пароль=:Password")    ;
			ADOQuery1->Parameters->ParamByName("FIO")->Value  = Edit1->Text;
			ADOQuery1->Parameters->ParamByName("Email")->Value    = Edit2->Text;
			ADOQuery1->Parameters->ParamByName("Login")->Value  = Edit3->Text;
			ADOQuery1->Parameters->ParamByName("Password")->Value    = Edit4->Text;
			ADOQuery1->ExecSQL();

			Edit1->Clear();
			Edit2->Clear();
			Edit3->Clear();
			Edit4->Clear();
			///////////////////////
			Application->Title="Успешно!";
			ShowMessage("Данные были успешно удалены.");
			}
		}
		ADOQuery1->Active=False;
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Text="select * from Users";
		ADOQuery1->Active=True;

	}
  }
  else
  {
    Application->Title="Внимание!";
	ShowMessage("Пожалуйста, заполните все поля для удаления администратора.");
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button4Click(TObject *Sender)
{
	DBGrid2->ReadOnly = false;
    Label4->Visible =false;
	Edit5->Visible =true;
	Edit6->Visible =true;
	ComboBox1->Visible =true;
	Edit8->Visible =true;
	Edit7->Visible =true;
	Edit9->Visible =true;
	ComboBox2->Visible =true;
	Button5->Visible =true;
	Button6->Visible =true;
	Button8->Visible =true;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Edit5KeyPress(TObject *Sender, System::WideChar &Key)
{
 if(Key == '_' ||Key == '.' ||Key == ',' ||Key == '?' ||Key == '!' ||Key == '>' ||Key == '<' ||Key == '/' || Key == '0' ||Key == '1' ||Key == '2' ||Key == '3' ||Key == '4' ||Key == '5' ||Key == '6' ||Key == '7' ||Key == '8' ||Key == '9'){
 Key = 0;
 }	
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button5Click(TObject *Sender)
{
	int counter_animal = 0;
	///Edit5
	if(Edit5->Text != "")
	{
		counter_animal++;
	}

	///Edit6
	if(Edit6->Text != "")
	{
		counter_animal++;
	}

	///ComboBox1
	if(ComboBox1->ItemIndex > -1)
	{
		counter_animal++;
	}
	///Edit7
	if(Edit7->Text != "")
	{
		counter_animal++;
	}
	
	///Edit8
	if(Edit8->Text != "")
	{
		counter_animal++;
	}

	///Edit9
	if(Edit9->Text != "")
	{
		counter_animal++;
	}

	///ComboBox2
	if(ComboBox2->ItemIndex > -1)
	{
		counter_animal++;
	}
	
	////////////////////////////////////////////
	if(Edit5->Text != "" && Edit6->Text != "" && Edit7->Text != "" && Edit8->Text != "" && Edit9->Text != "") {
		if(counter_animal == 7)
		{
			Application->Title="Успешно!";
			ShowMessage("Данные успешно занесены в БД.");
			AnsiString pole_1 = Edit5->Text;
			AnsiString pole_2 = Edit6->Text;
			AnsiString pole_3 = ComboBox1->Text;
			AnsiString pole_4 = Edit8->Text;
			AnsiString pole_5 = Edit9->Text;
			AnsiString pole_6 = ComboBox2->Text;
			AnsiString pole_7 = Edit7->Text;

			ADOQuery2->Close();
			ADOQuery3->Close();
			try {
				ADOQuery3->SQL->Text = "INSERT INTO Animals (Имя, Приют, Фото, Категория, Информация ) VALUES (\"" + pole_1 + "\",\"" + pole_4 + "\",\"" + pole_5 + "\",\"" + pole_6 + "\",\"" + pole_7 + "\")";
				ADOQuery3->Open();
			}
			catch(...)  { }
			ADOQuery3->Close();
			try
			{
				ADOQuery3->SQL->Text = "INSERT INTO INFO (Возраст, Пол, Информация) VALUES (\"" + pole_2 + "\",\"" + pole_3 + "\",\"" + pole_7 + "\")";
				ADOQuery3->Open();
			}
			catch(...)  { }
			ADOQuery3->Close();
			ADOQuery2->SQL->Text = "SELECT `Animals`.`Код`,`Animals`.`Категория`, `Animals`.`Имя`, `INFO`.`Возраст`, `INFO`.`Пол`, `Animals`.`Приют`, `Animals`.`Фото`, `INFO`.`Информация` FROM `Animals` INNER JOIN `INFO` ON `Animals`.`Информация`=`INFO`.`Информация`;";
			ADOQuery2->Open();
		}
		else
		{
			Application->Title="Внимание!";
			ShowMessage("Данные введены некорректно, пожалуйста перепроверьте.");
			counter_animal = 0;
		}
	}
	else
	{
		Application->Title="Внимание!";
		ShowMessage("Требуется заполнить все поля.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6Click(TObject *Sender)
{
if(Edit5->Text != "" && Edit6->Text != "" && Edit7->Text != "" && Edit8->Text != "" && Edit9->Text != "" && ComboBox1->ItemIndex != -1 && ComboBox2->ItemIndex != -1 ){
	//удалить животное из бд
	UnicodeString msg,ttl;
	msg = "Вы уверены, что хотите удалить эту запись?";
	ttl = "Подтверждение";
	if(Application->MessageBox(msg.c_str(),ttl.c_str(),MB_YESNO) == IDYES)
	{
		//удалить данные
		ADOQuery2->Active=False;
		ADOQuery2->SQL->Clear();
		ADOQuery2->SQL->Add("SELECT `Animals`.`Имя`, `INFO`.`Возраст` FROM `Animals` INNER JOIN `INFO` ON `Animals`.`Информация`=`INFO`.`Информация` WHERE Имя = :name and Возраст=:age and Пол=:pol and Приют=:home and Фото=:photo and Категория=:category and Animals.Информация=:info");
		ADOQuery2->Parameters->ParamByName("name")->Value = Edit5->Text;
		//нужно проверять по всем полям а не только по имени
		ADOQuery2->Parameters->ParamByName("age")->Value = Edit6->Text;
		ADOQuery2->Parameters->ParamByName("pol")->Value = ComboBox1->Text;
		ADOQuery2->Parameters->ParamByName("home")->Value = Edit8->Text;
		ADOQuery2->Parameters->ParamByName("photo")->Value = Edit9->Text;
		ADOQuery2->Parameters->ParamByName("category")->Value = ComboBox2->Text;
		ADOQuery2->Parameters->ParamByName("info")->Value = Edit7->Text;

		ADOQuery2->Active=True;

		if (!ADOQuery2->RecordCount){
			 Application->Title="Ошибка!";
			 ShowMessage ("Такой записи не существует.");
			 
		}
		else {

			ADOQuery2->Close();
			ADOQuery2->SQL->Clear();
			//  Категория=:Category and
			ADOQuery2->SQL->Add("delete from Animals where Имя=:Name and Фото=:Photo");
			ADOQuery2->Parameters->ParamByName("Name")->Value = Edit5->Text;
			ADOQuery2->Parameters->ParamByName("Photo")->Value = Edit9->Text;

			ADOQuery2->ExecSQL();

			Edit5->Clear();
			Edit6->Clear();
			Edit7->Clear();
			Edit8->Clear();
			Edit9->Clear();
			Edit5->SetFocus();
			///////////////////////
			Application->Title="Успешно!";
			ShowMessage("Данные были успешно удалены.");
		}
	}
		ADOQuery2->Active=False;
		ADOQuery2->SQL->Clear();
		ADOQuery2->SQL->Text="SELECT `Animals`.`Код`,`Animals`.`Категория`, `Animals`.`Имя`, `INFO`.`Возраст`, `INFO`.`Пол`, `Animals`.`Приют`, `Animals`.`Фото`,`INFO`.`Информация`FROM `Animals` INNER JOIN `INFO` ON `Animals`.`Информация`=`INFO`.`Информация` ";
		ADOQuery2->Active=True;
}
else
{
    Application->Title="Внимание!";
	ShowMessage("Требуется заполнить все поля.");
}

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button7Click(TObject *Sender)
{
	//Возвращаем в прежний вид
	ADOQuery1->Active = False;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text="SELECT * FROM Users";
	ADOQuery1->Active = True;
	//

	Edit1->Visible =false;
	Edit2->Visible =false;
	Edit3->Visible =false;
	Edit4->Visible =false;
	Button2->Visible = false;
	Button3->Visible =false;
	Button7->Visible =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button8Click(TObject *Sender)
{
	DBGrid2->ReadOnly = true;
    Label4->Visible = true;
	Edit5->Visible =false;
	Edit6->Visible =false;
	ComboBox1->Visible =false;
	Edit8->Visible =false;
	Edit7->Visible =false;
	Edit9->Visible =false;
	ComboBox2->Visible =false;
	Button5->Visible =false;
	Button6->Visible =false;
	Button8->Visible =false;

	//Персчитать лабел4
	col_counter = ADOQuery2->RecordCount;
	Label4->Caption = "Всего: " + IntToStr(col_counter);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button9Click(TObject *Sender)
{
	ADOQuery2->Active = False;
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Text="SELECT `Animals`.`Код`,`Animals`.`Категория`, `Animals`.`Имя`, `INFO`.`Возраст`, `INFO`.`Пол`, `Animals`.`Приют`, `Animals`.`Фото`,`INFO`.`Информация`FROM `Animals` INNER JOIN `INFO` ON `Animals`.`Информация`=`INFO`.`Информация` WHERE [Категория] = 'Кот'";
	ADOQuery2->Active = True;
    //Персчитать лабел4
	col_counter = ADOQuery2->RecordCount;
	Label4->Caption = "Всего: " + IntToStr(col_counter);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button10Click(TObject *Sender)
{
    ADOQuery2->Active = False;
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Text="SELECT `Animals`.`Код`,`Animals`.`Категория`, `Animals`.`Имя`, `INFO`.`Возраст`, `INFO`.`Пол`, `Animals`.`Приют`, `Animals`.`Фото`,`INFO`.`Информация`FROM `Animals` INNER JOIN `INFO` ON `Animals`.`Информация`=`INFO`.`Информация` WHERE [Категория] = 'Собака'";
	ADOQuery2->Active = True;
    //Персчитать лабел4
	col_counter = ADOQuery2->RecordCount;
	Label4->Caption = "Всего: " + IntToStr(col_counter);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button11Click(TObject *Sender)
{
    ADOQuery2->Active = False;
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Text="SELECT `Animals`.`Код`,`Animals`.`Категория`, `Animals`.`Имя`, `INFO`.`Возраст`, `INFO`.`Пол`, `Animals`.`Приют`, `Animals`.`Фото`,`INFO`.`Информация`FROM `Animals` INNER JOIN `INFO` ON `Animals`.`Информация`=`INFO`.`Информация` WHERE [Категория] = 'Птица'";
	ADOQuery2->Active = True;
	//Персчитать лабел4
	col_counter = ADOQuery2->RecordCount;
	Label4->Caption = "Всего: " + IntToStr(col_counter);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button12Click(TObject *Sender)
{
	ADOQuery2->Active=False;
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Text="SELECT `Animals`.`Код`,`Animals`.`Категория`, `Animals`.`Имя`, `INFO`.`Возраст`, `INFO`.`Пол`, `Animals`.`Приют`, `Animals`.`Фото`,`INFO`.`Информация`FROM `Animals` INNER JOIN `INFO` ON `Animals`.`Информация`=`INFO`.`Информация` ";
	ADOQuery2->Active=True;
    //Персчитать лабел4
	col_counter = ADOQuery2->RecordCount;
	Label4->Caption = "Всего: " + IntToStr(col_counter);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{
	col_counter = ADOQuery2->RecordCount;
	Label4->Caption = "Всего: " + IntToStr(col_counter);

	ADOQuery2->Active=False;
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Add("SELECT `Animals`.`Код`,`Animals`.`Категория`, `Animals`.`Имя`, `INFO`.`Возраст`, `INFO`.`Пол`, `Animals`.`Приют`, `Animals`.`Фото`,`INFO`.`Информация`FROM `Animals` INNER JOIN `INFO` ON `Animals`.`Информация`=`INFO`.`Информация` ;");    //Animals
	ADOQuery2->Active=True;
}
//---------------------------------------------------------------------------




void __fastcall TForm4::FormActivate(TObject *Sender)
{
    ADOQuery1->Active = false;
	ADOQuery1->Active = true;
}
//---------------------------------------------------------------------------

