object Form4: TForm4
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Form4'
  ClientHeight = 578
  ClientWidth = 765
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnActivate = FormActivate
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object Label1: TLabel
    Left = 48
    Top = 23
    Width = 154
    Height = 27
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Lucida Sans'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 271
    Width = 111
    Height = 27
    Caption = #1046#1080#1074#1086#1090#1085#1099#1077
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Lucida Sans'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 192
    Top = 280
    Width = 69
    Height = 15
    Caption = 'C'#1086#1088#1090#1080#1088#1086#1074#1082#1072':'
  end
  object Label4: TLabel
    Left = 664
    Top = 452
    Width = 49
    Height = 15
    Caption = #1042#1089#1077#1075#1086': 40'
  end
  object DBGrid1: TDBGrid
    Left = 48
    Top = 73
    Width = 665
    Height = 129
    DataSource = DataSource1
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = #1050#1086#1076
        Width = 25
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1060#1048#1054
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1055#1086#1095#1090#1072
        Width = 170
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1051#1086#1075#1080#1085
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1055#1072#1088#1086#1083#1100
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1058#1080#1087' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
        Width = 120
        Visible = True
      end>
  end
  object DBGrid2: TDBGrid
    Left = 48
    Top = 304
    Width = 665
    Height = 145
    DataSource = DataSource2
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = #1050#1086#1076
        Width = 25
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1050#1072#1090#1077#1075#1086#1088#1080#1103
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1048#1084#1103
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1042#1086#1079#1088#1072#1089#1090
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1055#1086#1083
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1055#1088#1080#1102#1090
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1060#1086#1090#1086
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103
        Width = 200
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 48
    Top = 208
    Width = 111
    Height = 25
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 184
    Top = 209
    Width = 121
    Height = 23
    TabOrder = 3
    TextHint = #1060#1048#1054
    Visible = False
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 320
    Top = 209
    Width = 121
    Height = 23
    TabOrder = 4
    TextHint = #1055#1086#1095#1090#1072
    Visible = False
  end
  object Edit3: TEdit
    Left = 455
    Top = 209
    Width = 121
    Height = 23
    TabOrder = 5
    TextHint = #1051#1086#1075#1080#1085
    Visible = False
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 592
    Top = 209
    Width = 121
    Height = 23
    TabOrder = 6
    TextHint = #1055#1072#1088#1086#1083#1100
    Visible = False
  end
  object Button2: TButton
    Left = 184
    Top = 238
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 7
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 48
    Top = 238
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 8
    Visible = False
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 48
    Top = 472
    Width = 111
    Height = 25
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 9
    OnClick = Button4Click
  end
  object Edit5: TEdit
    Left = 184
    Top = 473
    Width = 121
    Height = 23
    TabOrder = 10
    TextHint = #1048#1084#1103
    Visible = False
    OnKeyPress = Edit5KeyPress
  end
  object Edit6: TEdit
    Left = 320
    Top = 473
    Width = 121
    Height = 23
    TabOrder = 11
    TextHint = #1042#1086#1079#1088#1072#1089#1090
    Visible = False
  end
  object Edit8: TEdit
    Left = 592
    Top = 473
    Width = 121
    Height = 23
    TabOrder = 12
    TextHint = #1055#1088#1080#1102#1090
    Visible = False
  end
  object Edit9: TEdit
    Left = 184
    Top = 502
    Width = 201
    Height = 23
    TabOrder = 13
    TextHint = #1060#1086#1090#1086
    Visible = False
  end
  object Button5: TButton
    Left = 184
    Top = 531
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 14
    Visible = False
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 48
    Top = 503
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 15
    Visible = False
    OnClick = Button6Click
  end
  object ComboBox1: TComboBox
    Left = 455
    Top = 473
    Width = 121
    Height = 23
    TabOrder = 16
    TextHint = #1055#1086#1083
    Visible = False
    Items.Strings = (
      #1046#1077#1085#1089#1082#1080#1081
      #1052#1091#1078#1089#1082#1086#1081)
  end
  object ComboBox2: TComboBox
    Left = 592
    Top = 502
    Width = 121
    Height = 23
    TabOrder = 17
    TextHint = #1050#1072#1090#1077#1075#1086#1088#1080#1103
    Visible = False
    Items.Strings = (
      #1057#1086#1073#1072#1082#1072
      #1050#1086#1090
      #1055#1090#1080#1094#1072)
  end
  object Button7: TButton
    Left = 536
    Top = 238
    Width = 177
    Height = 25
    Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 18
    Visible = False
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 536
    Top = 531
    Width = 177
    Height = 25
    Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 19
    Visible = False
    OnClick = Button8Click
  end
  object Edit7: TEdit
    Left = 391
    Top = 502
    Width = 185
    Height = 23
    TabOrder = 20
    TextHint = #1048#1085#1092#1086#1088#1072#1094#1080#1103
    Visible = False
  end
  object Button9: TButton
    Left = 280
    Top = 276
    Width = 75
    Height = 21
    Caption = #1050#1086#1090#1099
    TabOrder = 21
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 366
    Top = 276
    Width = 75
    Height = 21
    Caption = #1057#1086#1073#1072#1082#1080
    TabOrder = 22
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 455
    Top = 276
    Width = 75
    Height = 21
    Caption = #1055#1090#1080#1094#1099
    TabOrder = 23
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 559
    Top = 276
    Width = 75
    Height = 21
    Caption = #1086#1090#1084#1077#1085#1072
    DoubleBuffered = False
    Font.Charset = ARABIC_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 24
    OnClick = Button12Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=C:\Us' +
      'ers\BOSS\OneDrive\'#1056#1072#1073#1086#1095#1080#1081' '#1089#1090#1086#1083'\'#1055#1088#1080#1102#1090' '#1078#1080#1074#1086#1090#1085#1099#1093'\Win32\Debug\User.m' +
      'db;Mode=Share Deny None;Persist Security Info=False;Jet OLEDB:Sy' +
      'stem database="";Jet OLEDB:Registry Path="";Jet OLEDB:Database P' +
      'assword="";Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking Mo' +
      'de=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk T' +
      'ransactions=1;Jet OLEDB:New Database Password="";Jet OLEDB:Creat' +
      'e System Database=False;Jet OLEDB:Encrypt Database=False;Jet OLE' +
      'DB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:Compact Without ' +
      'Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 496
    Top = 8
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from Users;')
    Left = 648
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 568
    Top = 8
  end
  object ADOConnection2: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=C:\Us' +
      'ers\BOSS\OneDrive\'#1056#1072#1073#1086#1095#1080#1081' '#1089#1090#1086#1083'\'#1055#1088#1080#1102#1090' '#1078#1080#1074#1086#1090#1085#1099#1093'\Win32\Debug\Animal' +
      '.mdb;Mode=Share Deny None;Persist Security Info=False;Jet OLEDB:' +
      'System database="";Jet OLEDB:Registry Path="";Jet OLEDB:Database' +
      ' Password="";Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking ' +
      'Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk' +
      ' Transactions=1;Jet OLEDB:New Database Password="";Jet OLEDB:Cre' +
      'ate System Database=False;Jet OLEDB:Encrypt Database=False;Jet O' +
      'LEDB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:Compact Withou' +
      't Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 320
    Top = 536
  end
  object DataSource2: TDataSource
    DataSet = ADOQuery2
    Left = 376
    Top = 536
  end
  object ADOQuery2: TADOQuery
    Active = True
    Connection = ADOConnection2
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT `Animals`.`'#1050#1086#1076'`,`Animals`.`'#1050#1072#1090#1077#1075#1086#1088#1080#1103'`, `Animals`.`'#1048#1084#1103'`,'
      
        '`INFO`.`'#1042#1086#1079#1088#1072#1089#1090'`, `INFO`.`'#1055#1086#1083'`, `Animals`.`'#1055#1088#1080#1102#1090'`, `Animals`.`'#1060#1086 +
        #1090#1086'`,'
      '`INFO`.`'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103'`  '
      
        'FROM `Animals` INNER JOIN `INFO` ON `Animals`.`'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103'`=`INFO' +
        '`.`'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103'`;')
    Left = 432
    Top = 536
  end
  object ADOQuery3: TADOQuery
    Connection = ADOConnection2
    CursorType = ctDynamic
    DataSource = DataSource2
    Parameters = <>
    Prepared = True
    Left = 488
    Top = 536
  end
end
