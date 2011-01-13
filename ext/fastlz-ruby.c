#ifdef _WIN32
__declspec(dllexport) void Init_fastlz(void);
#include <malloc.h>
#else
#include <alloca.h>
#endif

#include "fastlz.h"
#include "ruby.h"

#ifndef RSTRING_PTR
#define RSTRING_PTR(s) (RSTRING(s)->ptr)
#endif

#ifndef RSTRING_LEN
#define RSTRING_LEN(s) (RSTRING(s)->len)
#endif

/* */
static VALUE rb_fastlz_compress(int argc, VALUE *argv, VALUE self) {
  VALUE v_src, v_level;
  char *src, *dst;
  int slen, dlen, level;

  rb_scan_args(argc, argv, "11", &v_src, &v_level);
  Check_Type(v_src, T_STRING);

  if (NIL_P(v_level)) {
    level = 0;
  } else {
    level = NUM2INT(v_level);

    if (level != 1 || level != 2) {
      rb_raise(rb_eRuntimeError, "only level 1 and level 2 are supported");
    }
  }

  src = RSTRING_PTR(v_src);
  slen = RSTRING_LEN(v_src);

  dst = alloca(slen * 2);

  if (level) {
    dlen = fastlz_compress_level(level, src, slen, dst);
  } else {
    dlen = fastlz_compress(src, slen, dst);
  }

  return rb_str_new(dst, dlen);
}

/* */
static VALUE rb_fastlz_decompress(int argc, VALUE *argv, VALUE self) {
  VALUE v_src, v_max;
  char *src, *dst;
  int slen, dlen, max;

  rb_scan_args(argc, argv, "11", &v_src, &v_max);
  Check_Type(v_src, T_STRING);

  src = RSTRING_PTR(v_src);
  slen = RSTRING_LEN(v_src);

  if (NIL_P(v_max)) {
    max = slen * 4;
  } else {
    max = NUM2INT(v_max);
  }

  dst = alloca(max + 1);

  dlen = fastlz_decompress(src, slen, dst, max); 

  return rb_str_new(dst, dlen);
}

void Init_fastlz() {
  VALUE FastLZ = rb_define_module("FastLZ");
  rb_define_module_function(FastLZ, "compress", rb_fastlz_compress, -1);
  rb_define_module_function(FastLZ, "decompress", rb_fastlz_decompress, -1);
}
