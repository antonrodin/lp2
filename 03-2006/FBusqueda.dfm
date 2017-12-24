object Busqueda: TBusqueda
  Left = 159
  Top = 128
  Width = 447
  Height = 357
  Caption = 'Busqueda'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ok: TButton
    Left = 88
    Top = 272
    Width = 89
    Height = 33
    Caption = 'Ok'
    TabOrder = 0
    OnClick = okClick
  end
  object selOjos: TRadioGroup
    Left = 0
    Top = 152
    Width = 121
    Height = 105
    Caption = 'Tipo de ojos'
    Items.Strings = (
      'Redondos'
      'Gafas'
      'Rasgados')
    TabOrder = 1
    OnClick = selOjosClick
  end
  object selBoca: TRadioGroup
    Left = 304
    Top = 40
    Width = 129
    Height = 105
    Caption = 'Tipo de boca'
    Items.Strings = (
      'Larga'
      'Pequeña'
      'Delgada')
    TabOrder = 2
    OnClick = selBocaClick
  end
  object selOrejasYNariz: TRadioGroup
    Left = 304
    Top = 152
    Width = 129
    Height = 105
    Caption = 'Tipo de orejas y nariz'
    Items.Strings = (
      'Gancho'
      'Redonda'
      'Pequeña')
    TabOrder = 3
    OnClick = selOrejasYNarizClick
  end
  object selPelo: TRadioGroup
    Left = 0
    Top = 40
    Width = 121
    Height = 105
    Caption = 'Tipo de pelo'
    Items.Strings = (
      'Largo'
      'Raya'
      'Raso')
    TabOrder = 4
    OnClick = selPeloClick
  end
  object cara: TMemo
    Left = 124
    Top = 48
    Width = 173
    Height = 209
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Courier'
    Font.Style = [fsBold]
    Lines.Strings = (
      'cara')
    ParentFont = False
    TabOrder = 5
  end
  object cancel: TButton
    Left = 224
    Top = 272
    Width = 89
    Height = 33
    Caption = 'Cancel'
    TabOrder = 6
    OnClick = cancelClick
  end
end
