#include <stdlib.h>
#include <napi.h>
#include <hello.h>

void Hello(const Napi::CallbackInfo& info) {
    hello();
}

Napi::Number Add(const Napi::CallbackInfo& info) {
    Napi::Number a = info[0].As<Napi::Number>();
    Napi::Number b = info[1].As<Napi::Number>();
    int32_t result = add(a.Int32Value(), b.Int32Value());
    return Napi::Number::New(info.Env(), result);
}

Napi::Number FastSum(const Napi::CallbackInfo& info) {
    Napi::Number n = info[0].As<Napi::Number>();
    int32_t result = fast_sum(n.Int32Value());
    return Napi::Number::New(info.Env(), result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Hello));
  exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
  exports.Set(Napi::String::New(env, "fastSum"), Napi::Function::New(env, FastSum));
  return exports;
}

NODE_API_MODULE(hello_napi, Init)
