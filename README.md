Trap fatal exceptions in NodeJS and send
to IOpipe!

By changing the default behavior of NodeJS when
a fatalException occurs, we can run additional code
outside of the v8 engine for instrumentation purposes!
