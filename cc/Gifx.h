#ifndef __GIFX_GIFX_H__
#define __GIFX_GIFX_H__

#include <v8.h>
#include <nan.h>

using namespace v8;

class Gifx: public Nan::ObjectWrap {
  public:
    static Nan::Persistent<FunctionTemplate> constructor;
    static void Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target);
    static NAN_METHOD(New);
    static NAN_METHOD(Hello);

    Gifx();

  private:
    ~Gifx();
};

#endif
