#include "Gifx.h"

Nan::Persistent<FunctionTemplate> Gifx::constructor;

/*
 * Initialize Gifx.
 */

void
Gifx::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // Constructor
  Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(Gifx::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("Gifx").ToLocalChecked());

  Nan::SetPrototypeMethod(ctor, "hello", Hello);

  Nan::Set(target, Nan::New("Gifx").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Gifx::New) {
  if (!info.IsConstructCall()) {
    return Nan::ThrowTypeError("Class constructors cannot be invoked without 'new'");
  }

  info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Gifx::Hello) {
  info.GetReturnValue().Set(info.This());
}
