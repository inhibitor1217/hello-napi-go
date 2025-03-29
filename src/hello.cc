#include <stdio.h>
#include <napi.h>

void Method(const Napi::CallbackInfo& info) {
    printf("Hello, world!\n");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Method));
    return exports;
}

NODE_API_MODULE(hello, Init)
