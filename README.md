# I have no idea what I am doing!
This is more a proof of concept, run in production at your own risk.

This proves, that we can compile go code with cgo bindings to create vmods for varnish.

# Install
You need the following installed:
- varnish or varnish-plus.
- libvarnishapi.
- pkg-config

1) Process the *.vcc file with vmodtool to get magic stuff for varnish (Vmod data).
2) build the gocode.
3) Wait to see if it spits out errors or works.

# Build the vcc_if{.h,.c} file

```
/usr/share/varnish-plus/vmodtool.py vmod_example.vcc
```

This builds both the vcc_if.h file and the vcc_if.c file.

## Why do we need this?
Inside vcc_if.c, is code to create "Vmod_data", which is read by varnish to figure out what to do with the vmod "so" file.

# Build to vmod

```
go build  -buildmode=c-shared  -o libvmod_example.so main.go vcc_if.go
```

# Why
## Why unresolved-symbols=ignore-in-object-files
In main.go we use:
```
#cgo LDFLAGS: -Wl,--unresolved-symbols=ignore-in-object-files
```

This is to tell go build to ignore that it cant find functions, the functions are in the header files.

```
undefined reference to `WS_Release'
undefined reference to `WS_Reserve'
```


# Reference
- Based my code off work done by [hnakamur](https://github.com/hnakamur/) [here](https://github.com/hnakamur/docker-varnish-vmods-development/tree/try_to_create_vmod_in_go/varnish/libvmod_go_example)
