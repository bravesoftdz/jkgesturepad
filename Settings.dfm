object frmSettings: TfrmSettings
  Left = 0
  Top = 0
  Caption = 'JKGesture Settings'
  ClientHeight = 254
  ClientWidth = 494
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    494
    254)
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 95
    Top = 11
    Width = 69
    Height = 13
    Caption = 'Run Command'
  end
  object Label3: TLabel
    Left = 9
    Top = 11
    Width = 38
    Height = 13
    Caption = 'Gesture'
  end
  object btnOpen: TSpeedButton
    Left = 469
    Top = 30
    Width = 22
    Height = 21
    Anchors = [akTop, akRight]
    Flat = True
    Glyph.Data = {
      36030000424D3603000000000000360000002800000010000000100000000100
      18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFD8D8D89AA7AE83949E83949F8395A08496A18498A385
      99A5869AA6879AA7879CA9889DAA889FAC9BB0BDE2EAEFFFFFFFA5A5A57397AC
      376C8D396D8E3A6E8E3A6F8F3A6F903B70903B70913B71923B71933C72943C73
      953A72944F81A0FFFFFF949494849EAF497D9D6492AF6392AF6391AF6391AF62
      91AF6291AF6291AF6291AF6291AF6291AF5E8EAC3B7090E0EAF094949497A7B0
      3C6E8D4D83A34B81A24E83A44A80A2417A9D40799D417A9D40799D40799D4079
      9D5185A6396D8CBACAD5949494A9B4BA446B848DAFC46F9AB56C98B36996B267
      95B1598BAA497FA13C779B3E789C3E789C5689A84777969DAFB9949494C1C1C0
      557081AEC7D682A7BF80A6BD7DA4BC7AA2BA77A0B9759EB86E99B45B8CAB4B81
      A34F84A46592AD6E808F949494C2C0BF586D7ACBDCE6A7C1D2A4BFD0A1BDCE9E
      BCCD9CBACC98B6CA85AAC082A7BF80A6BE7DA4BCB4CCDC61717B949494C0BFBF
      767F848A9BA6AFBDC6B0BDC6ADBDC5ACBBC5AABAC4B2C2CDDBE6EEA0BDCE8EB0
      C588ABC2CEDEE7576C7A949494C0C0C0B5B6B69BA2A68D94998F979B92999E94
      9CA1969EA38B94996B7B84DDE9F0E5EFF6E3EEF5D5E5EE617480949494C1C1C1
      B6B6B6BCBCBCC2C2C2C6C6C6CCCCCCD1D1D1D7D7D7DEDDDDB8BEC283898D7F86
      897F868A666D70A8B1B6949494C2C2C2B8B8B8BDBDBDC3C3C3C8C8C8CDCDCDD6
      D6D6DEDEDEE2E2E2E5E5E5EAEAEAEEEEEEF4F4F49B9B9BFFFFFF959595D4D4D4
      B7B7B7BCBCBCC2C2C2C8C8C8DBDBDBEFEFEFD2D2D2D2D2D2D2D2D2D2D2D2D2D2
      D2B1B1B1C0C0C0FFFFFF9A9A9AEAEAEAF7F7F7F7F7F7F6F6F6F6F6F6E7E7E791
      9191C1C1C1C2C2C2C2C2C2C2C2C2C2C2C2DBDBDBFFFFFFFFFFFFEFEFEFA5A5A5
      979797979797979797979797A8A8A8F3F3F3FFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    OnClick = btnOpenClick
    ExplicitLeft = 367
  end
  object lstGestureCmds: TListBox
    Left = 0
    Top = 57
    Width = 494
    Height = 197
    Align = alBottom
    ItemHeight = 13
    PopupMenu = popGestureCmds
    TabOrder = 0
  end
  object cmbGesture: TComboBox
    Left = 8
    Top = 30
    Width = 113
    Height = 21
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 1
    Text = 'sgLeft'
    Items.Strings = (
      'sgLeft'
      'sgRight'
      'sgUp'
      'sgDown'
      'sgUpLeft'
      'sgUpRight'
      'sgDownLeft'
      'sgDownRight'
      'sgLeftUp'
      'sgLeftDown'
      'sgRightUp'
      'sgRightDown'
      'sgUpDown'
      'sgDownUp'
      'sgLeftRight'
      'sgRightLeft'
      'sgUpLeftLong'
      'sgUpRightLong'
      'sgDownLeftLong'
      'sgDownRightLong'
      'sgScratchout'
      'sgTriangle'
      'sgSquare'
      'sgCheck'
      'sgCurlicue'
      'sgDoubleCurlicue'
      'sgCircle'
      'sgDoubleCircle'
      'sgSemiCircleLeft'
      'sgSemiCircleRight'
      'sgChevronUp'
      'sgChevronDown'
      'sgChevronLeft'
      'sgChevronRight'
      'a'
      'b'
      'c'
      'd'
      'e'
      'f'
      'g')
  end
  object edtRunCmd: TEdit
    Left = 123
    Top = 31
    Width = 342
    Height = 19
    Anchors = [akLeft, akTop, akRight]
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnKeyDown = edtRunCmdKeyDown
    ExplicitWidth = 240
  end
  object popGestureCmds: TPopupMenu
    Left = 112
    Top = 80
    object Delete1: TMenuItem
      Caption = 'Delete'
      OnClick = Delete1Click
    end
  end
  object dlgOpen: TOpenDialog
    InitialDir = 'C:\'
    Left = 192
    Top = 96
  end
end
