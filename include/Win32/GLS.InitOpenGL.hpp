﻿// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.InitOpenGL.pas' rev: 36.00 (Windows)

#ifndef GLS_InitOpenGLHPP
#define GLS_InitOpenGLHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGL.hpp>
#include <Winapi.OpenGLext.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Forms.hpp>
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Initopengl
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLOpenGL;
class DELPHICLASS TGLShader;
class DELPHICLASS TGLShaderV;
class DELPHICLASS TGLShaderG;
class DELPHICLASS TGLShaderF;
class DELPHICLASS TGLProgram;
template<typename _TYPE_> class DELPHICLASS TGLBuffer__1;
template<typename _TYPE_> class DELPHICLASS TGLBufferV__1;
template<typename _TYPE_> class DELPHICLASS TGLBufferI__1;
template<typename _TYPE_> class DELPHICLASS TGLBufferU__1;
class DELPHICLASS TGLArray;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLOpenGL : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Forms::TCustomForm* CustomForm;
	HWND _WND;
	HDC _DC;
	
protected:
	Winapi::Windows::TPixelFormatDescriptor _PFD;
	int _PFI;
	HGLRC _RC;
	void __fastcall SetPFD(const Winapi::Windows::TPixelFormatDescriptor &PFD_);
	void __fastcall SetPFI(const int PFI_);
	void __fastcall CreateWindow();
	void __fastcall DestroyWindow();
	void __fastcall ValidatePFD(const Winapi::Windows::TPixelFormatDescriptor &PFD_);
	void __fastcall ValidatePFI(const int PFI_);
	void __fastcall CreateDC();
	void __fastcall DestroyDC();
	void __fastcall CreateRC();
	void __fastcall DestroyRC();
	
public:
	__fastcall TGLOpenGL();
	__fastcall virtual ~TGLOpenGL();
	__property Winapi::Windows::TPixelFormatDescriptor PFD = {read=_PFD, write=SetPFD};
	__property int PFI = {read=_PFI, write=SetPFI, nodefault};
	__property HGLRC RC = {read=_RC, nodefault};
	__classmethod Winapi::Windows::TPixelFormatDescriptor __fastcall DefaultPFD();
	void __fastcall BeginGL();
	void __fastcall EndGL();
	void __fastcall InitOpenGL();
	void __fastcall ApplyPixelFormat(const HDC DC_);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLShader : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	unsigned _ID;
	
public:
	__fastcall TGLShader(const unsigned Kind_);
	__fastcall virtual ~TGLShader();
	__property unsigned ID = {read=_ID, nodefault};
	void __fastcall SetSource(const System::UnicodeString Source_);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLShaderV : public TGLShader
{
	typedef TGLShader inherited;
	
public:
	__fastcall TGLShaderV();
	__fastcall virtual ~TGLShaderV();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLShaderG : public TGLShader
{
	typedef TGLShader inherited;
	
public:
	__fastcall TGLShaderG();
	__fastcall virtual ~TGLShaderG();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLShaderF : public TGLShader
{
	typedef TGLShader inherited;
	
public:
	__fastcall TGLShaderF();
	__fastcall virtual ~TGLShaderF();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLProgram : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	unsigned _ID;
	
public:
	__fastcall TGLProgram();
	__fastcall virtual ~TGLProgram();
	void __fastcall Attach(TGLShader* const Shader_);
	void __fastcall Detach(TGLShader* const Shader_);
	void __fastcall Link();
	void __fastcall Use();
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename _TYPE_> class PASCALIMPLEMENTATION TGLBuffer__1 : public System::TObject
{
	typedef System::TObject inherited;
	
	
public:
	typedef _TYPE_ *_PValue_;
	
	
protected:
	unsigned _ID;
	unsigned _Kind;
	int _Count;
	_PValue_ _Head;
	void __fastcall SetCount(const int Count_);
	
public:
	__fastcall TGLBuffer__1(const unsigned Kind_);
	__fastcall virtual ~TGLBuffer__1();
	__property unsigned ID = {read=_ID, nodefault};
	__property int Count = {read=_Count, write=SetCount, nodefault};
	void __fastcall Bind();
	void __fastcall Unbind();
	void __fastcall Map();
	void __fastcall Unmap();
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename _TYPE_> class PASCALIMPLEMENTATION TGLBufferV__1 : public TGLBuffer__1<_TYPE_>
{
	typedef TGLBuffer__1<_TYPE_> inherited;
	
public:
	__fastcall TGLBufferV__1();
	__fastcall virtual ~TGLBufferV__1();
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename _TYPE_> class PASCALIMPLEMENTATION TGLBufferI__1 : public TGLBuffer__1<_TYPE_>
{
	typedef TGLBuffer__1<_TYPE_> inherited;
	
public:
	__fastcall TGLBufferI__1();
	__fastcall virtual ~TGLBufferI__1();
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename _TYPE_> class PASCALIMPLEMENTATION TGLBufferU__1 : public TGLBuffer__1<_TYPE_>
{
	typedef TGLBuffer__1<_TYPE_> inherited;
	
public:
	__fastcall TGLBufferU__1();
	__fastcall virtual ~TGLBufferU__1();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLArray : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	unsigned _ID;
	
public:
	__fastcall TGLArray();
	__fastcall virtual ~TGLArray();
	__property unsigned ID = {read=_ID, nodefault};
	void __fastcall BeginBind();
	void __fastcall EndBind();
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TGLOpenGL* GLOpenGL;
}	/* namespace Initopengl */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_INITOPENGL)
using namespace Gls::Initopengl;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_InitOpenGLHPP
