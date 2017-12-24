object Delincuentes: TDelincuentes
  Left = 235
  Top = 133
  Width = 642
  Height = 513
  Caption = 'Delincuentes'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 112
    Top = 32
    Width = 56
    Height = 20
    Caption = 'Nombre'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 112
    Top = 64
    Width = 49
    Height = 20
    Caption = 'Delitos'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 232
    Top = 0
    Width = 137
    Height = 24
    Caption = 'Ficha número:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object nFicha: TLabel
    Left = 392
    Top = 0
    Width = 65
    Height = 24
    Caption = 'nFicha'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 48
    Top = 440
    Width = 166
    Height = 20
    Caption = 'Registro de errores: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object botonAgregar: TButton
    Left = 32
    Top = 384
    Width = 113
    Height = 41
    Caption = 'Agregar'
    TabOrder = 0
    OnClick = botonAgregarClick
  end
  object selOjos: TRadioGroup
    Left = 104
    Top = 280
    Width = 113
    Height = 89
    Caption = 'Tipo de ojos'
    Items.Strings = (
      'Redondos'
      'Gafas'
      'Rasgados')
    TabOrder = 1
    OnClick = selOjosClick
  end
  object selBoca: TRadioGroup
    Left = 424
    Top = 168
    Width = 113
    Height = 97
    Caption = 'Tipo de boca'
    Items.Strings = (
      'Larga'
      'Pequeña'
      'Delgada')
    TabOrder = 2
    OnClick = selBocaClick
  end
  object selOrejasYNariz: TRadioGroup
    Left = 424
    Top = 280
    Width = 113
    Height = 89
    Caption = 'Tipo de orejas y nariz'
    Items.Strings = (
      'Gancho'
      'Redonda'
      'Pequeña')
    TabOrder = 3
    OnClick = selOrejasYNarizClick
  end
  object selPelo: TRadioGroup
    Left = 104
    Top = 168
    Width = 113
    Height = 97
    Caption = 'Tipo de pelo'
    Items.Strings = (
      'Largo'
      'Raya'
      'Raso')
    TabOrder = 4
    OnClick = selPeloClick
  end
  object cara: TMemo
    Left = 236
    Top = 172
    Width = 173
    Height = 197
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Courier'
    Font.Style = [fsBold]
    Lines.Strings = (
      'cara')
    ParentFont = False
    ReadOnly = True
    TabOrder = 5
  end
  object botonBorrar: TButton
    Left = 192
    Top = 384
    Width = 113
    Height = 41
    Caption = 'Borrar'
    TabOrder = 6
    OnClick = botonBorrarClick
  end
  object botonModificar: TButton
    Left = 344
    Top = 384
    Width = 113
    Height = 41
    Caption = 'Modificar'
    TabOrder = 7
    OnClick = botonModificarClick
  end
  object botonBuscar: TButton
    Left = 480
    Top = 384
    Width = 113
    Height = 41
    Caption = 'Buscar'
    TabOrder = 8
    OnClick = botonBuscarClick
  end
  object botonAnterior: TButton
    Left = 16
    Top = 16
    Width = 73
    Height = 353
    Caption = '<'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = botonAnteriorClick
  end
  object botonSiguiente: TButton
    Left = 552
    Top = 16
    Width = 73
    Height = 353
    Caption = '>'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 10
    OnClick = botonSiguienteClick
  end
  object MemoDelitos: TMemo
    Left = 184
    Top = 64
    Width = 353
    Height = 97
    Lines.Strings = (
      'MemoDelitos')
    TabOrder = 11
  end
  object EditNombre: TEdit
    Left = 184
    Top = 32
    Width = 177
    Height = 21
    TabOrder = 12
    Text = 'EditNombre'
  end
  object Registro: TMemo
    Left = 232
    Top = 440
    Width = 361
    Height = 41
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Registro')
    ParentFont = False
    TabOrder = 13
  end
end
