class MyInterfaceImpl : public IMyInterface {
public:
    MyInterfaceImpl() : refCount(1) {
        lpVtbl = &vtbl;
    }

    // Implement IUnknown methods
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject) override;
    ULONG STDMETHODCALLTYPE AddRef() override;
    ULONG STDMETHODCALLTYPE Release() override;

    // Implement Method17
    HRESULT STDMETHODCALLTYPE Method17() override {
        // Implementation of the method
        return S_OK; // Return success
    }

private:
    LONG refCount;
    static IMyInterfaceVtbl vtbl;
};

// Initialize the vtable
IMyInterfaceVtbl MyInterfaceImpl::vtbl = {
    // Assign function pointers to the vtable
    &MyInterfaceImpl::QueryInterface,
    &MyInterfaceImpl::AddRef,
    &MyInterfaceImpl::Release,
    &MyInterfaceImpl::Method17,
};
