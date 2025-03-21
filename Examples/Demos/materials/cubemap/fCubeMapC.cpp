// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fCubeMapC.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.BaseClasses"
#pragma link "GLS.Coordinates"

#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.GeomObjects"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.Texture"
#pragma link "GLS.FileDDS"
#pragma link "GLS.VectorFileObjects"
#pragma resource "*.dfm"
TForm1* Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}

// ---------------------------------------------------------------------------
void __fastcall TForm1::GLSceneViewer1BeforeRender(TObject* Sender)
{
    // CubmapSupported = !GL_ARB_texture_cube_map;
    GLSceneViewer1->BeforeRender = NULL;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject* Sender)
{
    // Our cube map images are here
    TFileName Path = GetCurrentAssetPath();
    SetCurrentDir(Path + "\\cubemap");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnApplyClick(TObject* Sender)
{
    // We need a CubeMapImage, which unlike the "regular Images" stores multiple images.

    Teapot1->Material->Texture->ImageClassName =
        __classid(TGLCubeMapImage)->ClassName();
    TGLCubeMapImage* Image =
        (TGLCubeMapImage*)Teapot1->Material->Texture->Image;

    // Load all 6 texture map components of the cube map
    // The 'PX', 'NX', etc. refer to 'positive X', 'negative X', etc.
	// and follow the RenderMan specs/conventions
    // apply .dds cubemaps to next objects
    DDStex(Teapot1->Material->Texture, "skybox.dds");
	// Select reflection cube map environment mapping
	// This is the mode you'll most commonly use with cube maps, normal cube
	// map generation is also supported (used for diffuse environment lighting)
	Teapot1->Material->Texture->MappingMode = tmmCubeMapReflection;
	// That's all folks, let us see the thing!
	Teapot1->Material->Texture->Disabled = false;
	// apply .dds cubemaps to next objects
    DDStex(Plane1->Material->Texture, "skybox.dds");
    Plane1->Material->Texture->MappingMode = tmmEyeLinear;

    btnApply->Visible = false;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::GLSceneViewer1MouseDown(
    TObject* Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    mx = X;
    my = Y;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::GLSceneViewer1MouseMove(
    TObject* Sender, TShiftState Shift, int X, int Y)
{
    if (Shift.Contains(ssLeft))
        GLCamera1->MoveAroundTarget(my - Y, mx - X);
    else if (Shift.Contains(ssRight))
        GLCamera1->RotateTarget(my - Y, mx - X, 0);
    mx = X;
    my = Y;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject* Sender, TShiftState Shift,
    int WheelDelta, TPoint &MousePos, bool &Handled)
{
    GLCamera1->AdjustDistanceToTarget(Power(1.1, (WheelDelta / 120.0)));
}
//---------------------------------------------------------------------------

