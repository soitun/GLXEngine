unit fPathControlD;

interface

uses
  Winapi.OpenGL,
  System.SysUtils,
  System.Classes,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.ComCtrls,
  Vcl.ExtCtrls,
  Vcl.StdCtrls,
  Vcl.Buttons,

  
  GLS.Scene,
  GLS.Objects,
  Stage.VectorGeometry,
  GLS.Cadencer,
  GLS.Behaviours,
  GLS.Graph,
  GLS.Movement,
  Stage.VectorTypes,
  GLS.SceneViewer,
  GLS.ImageUtils,
 
  GLS.Coordinates,
  GLS.BaseClasses,
  Stage.Utils,
  GLS.SimpleNavigation;

type
  TFormPathControl = class(TForm)
    GLScene1: TGLScene;
    GLSceneViewer1: TGLSceneViewer;
    Cube2: TGLCube;
    GLCamera1: TGLCamera;
    GLLightSource1: TGLLightSource;
    DummyCube1: TGLDummyCube;
    GLCadencer1: TGLCadencer;
    MoveBtn: TBitBtn;
    Sphere1: TGLSphere;
    GLSimpleNavigation1: TGLSimpleNavigation;
    procedure FormActivate(Sender: TObject);
    procedure MoveBtnClick(Sender: TObject);
  private
    procedure PathTravelStop(Sender: TObject; Path: TGLMovementPath; var Looped: Boolean);
    procedure PathAllTravelledOver(Sender: TObject);
  public
  end;

var
  FormPathControl: TFormPathControl;

implementation

{$R *.DFM}

procedure TFormPathControl.FormActivate(Sender: TObject);
var
  Movement: TGLMovement;
  Path:     TGLMovementPath;
  Node:     TGLPathNode;
begin
  // Create a movement, a path and the first node of the path.
  Movement   := GetOrCreateMovement(Cube2);
  Movement.OnPathTravelStop := PathTravelStop;
  Movement.OnAllPathTravelledOver := PathAllTravelledOver;
  Path       := Movement.AddPath;
  Path.ShowPath := True;

  // Path.StartTime := 2;
  // Path.Looped := True;

  Node       := Path.AddNodeFromObject(Cube2);
  Node.Speed := 4.0;

  // Add a node.
  Node       := Path.AddNode;
  Node.Speed := 4.0;
  Node.PositionAsVector := VectorMake(-10, 0, 0, 1);
  Node.RotationAsVector := VectorMake(0, 0, 0);

  // Add a node.
  Node       := Path.AddNode;
  Node.Speed := 4.0;
  Node.PositionAsVector := VectorMake(0, 5, - 5);
  Node.RotationAsVector := VectorMake(0, 90, 0);

  // Add a node.
  Node       := Path.AddNode;
  Node.Speed := 4.0;
  Node.PositionAsVector := VectorMake(6, - 5, 2);
  Node.RotationAsVector := VectorMake(0, 180, 0);

  // Add a node.
  Node       := Path.AddNode;
  Node.Speed := 4.0;
  Node.PositionAsVector := VectorMake(-6, 0, 0);
  Node.RotationAsVector := VectorMake(0, 259, 0);

  // Activatived the current path.
  Movement.ActivePathIndex := 0;
end;

procedure TFormPathControl.MoveBtnClick(Sender: TObject);
var
  Movement: TGLMovement;
begin
  Movement := GetMovement(Cube2);
  if Assigned(Movement) then begin
      Movement.StartPathTravel;
      GLCadencer1.Enabled := True;
  end;
end;

procedure TFormPathControl.PathTravelStop(Sender: TObject; Path: TGLMovementPath; var Looped: Boolean);
begin
   if not Application.Terminated then
      InformationDlg('Path Travel Stopped');
end;

procedure TFormPathControl.PathAllTravelledOver(Sender: TObject);
begin
   if not Application.Terminated then
      InformationDlg('All Path(es) Traveled Over');
end;

end.
