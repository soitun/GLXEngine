//---------------------------------------------------------------------------

#ifndef fSmoothNaviCH
#define fSmoothNaviCH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <tchar.h>
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "GLS.BaseClasses.hpp"
#include "GLS.Cadencer.hpp"
#include "GLS.Coordinates.hpp"

#include "GLS.GeomObjects.hpp"
#include "GLS.Graph.hpp"
#include "GLS.Objects.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
#include "GLS.SmoothNavigator.hpp"
#include "Stage.Keyboard.hpp"
#include "Stage.Utils.hpp"


//---------------------------------------------------------------------------
class TFormSmoothnavi : public TForm
{
__published:	// IDE-managed Components
	TGLSceneViewer *GLSceneViewer1;
	TPanel *Panel3;
	TCheckBox *MouseLookCheckBox;
	TGroupBox *GroupBox2;
	TRadioButton *RadioButton6;
	TRadioButton *RadioButton7;
	TRadioButton *RadioButton8;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TPanel *Panel1;
	TGLScene *GLScene1;
	TGLDummyCube *scene;
	TGLXYZGrid *GLXYZGrid1;
	TGLLightSource *GLLightSource1;
	TGLSphere *GLSphere1;
	TGLArrowLine *GLArrowLine1;
	TGLCamera *GLCamera1;
	TGLCadencer *GLCadencer1;
	TTimer *FPSTimer;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall GLCadencer1Progress(TObject *Sender, const double deltaTime, const double newTime);
	void __fastcall FPSTimerTimer(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall MouseLookCheckBoxClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RadioButton6Click(TObject *Sender);
	void __fastcall RadioButton7Click(TObject *Sender);
	void __fastcall RadioButton8Click(TObject *Sender);
	void __fastcall GLSceneViewer1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall GLSceneViewer1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);

private:	// User declarations
	TGLSmoothUserInterface *UI;
	TGLSmoothNavigator *Navigator;
	//  RealPos: TPoint;

	TShiftState ShiftState;
	int xx, yy;
	int NewXX, NewYY;
	void __fastcall  CheckControls(double DeltaTime, double newTime);


public:		// User declarations
	__fastcall TFormSmoothnavi(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSmoothnavi *FormSmoothnavi;
//---------------------------------------------------------------------------
#endif
