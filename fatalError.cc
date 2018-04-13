#include <node.h>
#include <stdlib.h>
#include <v8.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void OnFatalError(const char* location, const char* message) {
  if (location) {
    printf("ERICA FATAL ERROR: %s %s\n", location, message);
  } else {
    printf("ERICA FATAL ERROR: %s\n", message);
  }
  //fflush(stderr);
  //ABORT();
  //node::Abort(); 
  abort();
}

void registerHandler(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  isolate->SetFatalErrorHandler(OnFatalError);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "register", registerHandler);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo
