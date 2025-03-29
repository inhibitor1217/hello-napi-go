#include <stdio.h>
#include <napi.h>

void Hello(const Napi::CallbackInfo& info) {
    printf("Hello, world!\n");
}

Napi::Number Add(const Napi::CallbackInfo& info) {
    Napi::Number a = info[0].As<Napi::Number>();
    Napi::Number b = info[1].As<Napi::Number>();
    return Napi::Number::New(info.Env(), a.Int32Value() + b.Int32Value());
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Hello));
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
    return exports;
}

NODE_API_MODULE(hello, Init)
