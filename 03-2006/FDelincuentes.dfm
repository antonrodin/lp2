object Delincuentes: TDelincuentes
  Left = 315
  Top = 162
  Width = 642
  Height = 576
  Caption = 'Delincuentes'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
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
    Top = 480
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
  object canvas: TImage
    Left = 248
    Top = 112
    Width = 150
    Height = 150
    OnClick = canvasClick
  end
  object botonAgregar: TButton
    Left = 24
    Top = 424
    Width = 113
    Height = 41
    Caption = 'Agregar'
    TabOrder = 0
    OnClick = botonAgregarClick
  end
  object selOjos: TRadioGroup
    Left = 104
    Top = 320
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
    Top = 216
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
    Top = 320
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
    Top = 216
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
    Left = 248
    Top = 272
    Width = 153
    Height = 145
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Courier'
    Font.Style = [fsBold]
    Lines.Strings = (
      'cara')
    ParentFont = False
    ReadOnly = True
    TabOrder = 5
  end
  object botonBorrar: TButton
    Left = 168
    Top = 424
    Width = 113
    Height = 41
    Caption = 'Borrar'
    TabOrder = 6
    OnClick = botonBorrarClick
  end
  object botonModificar: TButton
    Left = 312
    Top = 424
    Width = 113
    Height = 41
    Caption = 'Modificar'
    TabOrder = 7
    OnClick = botonModificarClick
  end
  object botonBuscar: TButton
    Left = 456
    Top = 424
    Width = 113
    Height = 41
    Caption = 'Buscar'
    TabOrder = 8
    OnClick = botonBuscarClick
  end
  object botonAnterior: TButton
    Left = 16
    Top = 48
    Width = 73
    Height = 321
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
    Top = 56
    Width = 73
    Height = 313
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
    Height = 41
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
    Top = 480
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
  object MainMenu1: TMainMenu
    Left = 16
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object Nuevo: TMenuItem
        Caption = 'Nuevo'
      end
      object Guardartxt1: TMenuItem
        Caption = ' '
      end
      object AbrirTXT: TMenuItem
        Caption = 'Abrit .txt'
        OnClick = AbrirTXTClick
      end
      object GuardarTXT: TMenuItem
        Caption = 'Guardar .txt'
        OnClick = GuardarTXTClick
      end
      object GuardarComoTXT: TMenuItem
        Caption = 'Guardar como .txt'
        OnClick = GuardarComoTXTClick
      end
      object Salir2: TMenuItem
        Caption = ' '
      end
      object Salir: TMenuItem
        Caption = 'Salir'
      end
    end
    object Lista1: TMenuItem
      Caption = 'Lista'
      object Nueva1: TMenuItem
        Caption = 'Nueva'
        OnClick = Nueva1Click
      end
      object N1: TMenuItem
        Caption = ' '
      end
      object Aadir1: TMenuItem
        Caption = 'Añadir'
        OnClick = Aadir1Click
      end
      object Modificar1: TMenuItem
        Caption = 'Modificar'
        OnClick = Modificar1Click
      end
      object Eliminar1: TMenuItem
        Caption = 'Eliminar'
        OnClick = Eliminar1Click
      end
      object Buscar1: TMenuItem
        Caption = 'Buscar'
      end
    end
  end
  object Abrir: TOpenDialog
    Left = 56
  end
  object Salvar: TSaveDialog
    Left = 96
  end
  object AbrirBMP: TOpenPictureDialog
    Left = 136
  end
end
