; Tower of Hanoi Visualizer - Inno Setup Script

[Setup]
AppName=Tower of Hanoi Visualizer
AppVersion=1.0
AppPublisher=Binay Bista
AppPublisherURL=
AppSupportURL=
AppUpdatesURL=
DefaultDirName={pf64}\TowerOfHanoi
DefaultGroupName=Tower of Hanoi Visualizer
OutputDir=.
OutputBaseFilename=TowerOfHanoi_Setup
Compression=lzma
SolidCompression=yes
CloseApplications=no
ArchitecturesInstallIn64BitMode=x64
ArchitecturesAllowed=x64
UninstallDisplayName=Tower of Hanoi Visualizer
UninstallDisplayIcon={app}\hanoi.exe

; this will make it appear in Add/Remove Programs
AppId={{A1B2C3D4-E5F6-7890-ABCD-EF1234567890}

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "Create a &desktop shortcut"; GroupDescription: "Additional icons:"; Flags: unchecked

[Files]
; main executable
Source: "hanoi.exe"; DestDir: "{app}"; Flags: ignoreversion

; raylib dll - required to run the app
Source: "raylib.dll"; DestDir: "{app}"; Flags: ignoreversion skipifsourcedoesntexist

; any other dlls your app needs
Source: "*.dll"; DestDir: "{app}"; Flags: ignoreversion skipifsourcedoesntexist

[Icons]
; start menu shortcut
Name: "{group}\Tower of Hanoi Visualizer"; Filename: "{app}\hanoi.exe"

; desktop shortcut
Name: "{commondesktop}\Tower of Hanoi Visualizer"; Filename: "{app}\hanoi.exe"; Tasks: desktopicon

; uninstall shortcut in start menu
Name: "{group}\Uninstall Tower of Hanoi Visualizer"; Filename: "{uninstallexe}"

[Run]
; option to launch after install
Filename: "{app}\hanoi.exe"; Description: "Launch Tower of Hanoi Visualizer"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
; clean up everything on uninstall
Type: filesandordirs; Name: "{app}"
