// Filename: glCgShaderContext_src.h
// Created by: jyelon (01Sep05)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#if defined(HAVE_CG) && !defined(OPENGLES)

#include "pandabase.h"
#include "string_utils.h"
#include "internalName.h"
#include "shader.h"
#include "shaderContext.h"
#include "deletedChain.h"

#include <Cg/cg.h>

class CLP(GraphicsStateGuardian);

////////////////////////////////////////////////////////////////////
//       Class : GLShaderContext
// Description : xyz
////////////////////////////////////////////////////////////////////
class EXPCL_GL CLP(CgShaderContext) : public ShaderContext {
public:
  friend class CLP(GraphicsStateGuardian);

  CLP(CgShaderContext)(CLP(GraphicsStateGuardian) *glgsg, Shader *s);
  ~CLP(CgShaderContext)();
  ALLOC_DELETED_CHAIN(CLP(CgShaderContext));

  INLINE bool valid(void);
  void bind(bool reissue_parameters = true);
  void unbind();
  void issue_parameters(int altered);
  void disable_shader_vertex_arrays();
  bool update_shader_vertex_arrays(ShaderContext *prev, bool force);
  void disable_shader_texture_bindings();
  void update_shader_texture_bindings(ShaderContext *prev);

  INLINE bool uses_standard_vertex_arrays(void);
  INLINE bool uses_custom_vertex_arrays(void);
  INLINE bool uses_custom_texture_bindings(void);

private:
  CGprogram _cg_program;

  pvector<CGparameter> _cg_parameter_map;

  CLP(GraphicsStateGuardian) *_glgsg;

  void release_resources();

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    TypedObject::init_type();
    register_type(_type_handle, CLASSPREFIX_QUOTED "CgShaderContext",
                  TypedObject::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "glCgShaderContext_src.I"

#endif  // OPENGLES_1

