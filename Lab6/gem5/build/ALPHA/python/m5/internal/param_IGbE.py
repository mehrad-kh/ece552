# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.4
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.



from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_param_IGbE', [dirname(__file__)])
        except ImportError:
            import _param_IGbE
            return _param_IGbE
        if fp is not None:
            try:
                _mod = imp.load_module('_param_IGbE', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _param_IGbE = swig_import_helper()
    del swig_import_helper
else:
    import _param_IGbE
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


def _swig_setattr_nondynamic_method(set):
    def set_attr(self,name,value):
        if (name == "thisown"): return self.this.own(value)
        if hasattr(self,name) or (name == "this"):
            set(self,name,value)
        else:
            raise AttributeError("You cannot add attributes to %s" % self)
    return set_attr


class EthAddr(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _param_IGbE.new_EthAddr(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _param_IGbE.delete_EthAddr
    __del__ = lambda self : None;
EthAddr_swigregister = _param_IGbE.EthAddr_swigregister
EthAddr_swigregister(EthAddr)

class IpAddress(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _param_IGbE.new_IpAddress(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _param_IGbE.delete_IpAddress
    __del__ = lambda self : None;
IpAddress_swigregister = _param_IGbE.IpAddress_swigregister
IpAddress_swigregister(IpAddress)

class IpNetmask(IpAddress):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _param_IGbE.new_IpNetmask(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _param_IGbE.delete_IpNetmask
    __del__ = lambda self : None;
IpNetmask_swigregister = _param_IGbE.IpNetmask_swigregister
IpNetmask_swigregister(IpNetmask)

class IpWithPort(IpAddress):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _param_IGbE.new_IpWithPort(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _param_IGbE.delete_IpWithPort
    __del__ = lambda self : None;
IpWithPort_swigregister = _param_IGbE.IpWithPort_swigregister
IpWithPort_swigregister(IpWithPort)

import param_EtherDevice
import param_PciDevice
import param_Platform
import param_IntrControl
import param_System
import enum_MemoryMode
import AbstractMemory_vector
import param_AbstractMemory
import range
import param_MemObject
import param_SimObject
import param_DmaDevice
import param_PioDevice
class IGbE(param_EtherDevice.EtherDevice):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
IGbE_swigregister = _param_IGbE.IGbE_swigregister
IGbE_swigregister(IGbE)

class IGbEParams(param_EtherDevice.EtherDeviceParams):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def create(self): return _param_IGbE.IGbEParams_create(self)
    hardware_address = _swig_property(_param_IGbE.IGbEParams_hardware_address_get, _param_IGbE.IGbEParams_hardware_address_set)
    fetch_delay = _swig_property(_param_IGbE.IGbEParams_fetch_delay_get, _param_IGbE.IGbEParams_fetch_delay_set)
    use_flow_control = _swig_property(_param_IGbE.IGbEParams_use_flow_control_get, _param_IGbE.IGbEParams_use_flow_control_set)
    clock = _swig_property(_param_IGbE.IGbEParams_clock_get, _param_IGbE.IGbEParams_clock_set)
    phy_pid = _swig_property(_param_IGbE.IGbEParams_phy_pid_get, _param_IGbE.IGbEParams_phy_pid_set)
    tx_fifo_size = _swig_property(_param_IGbE.IGbEParams_tx_fifo_size_get, _param_IGbE.IGbEParams_tx_fifo_size_set)
    tx_desc_cache_size = _swig_property(_param_IGbE.IGbEParams_tx_desc_cache_size_get, _param_IGbE.IGbEParams_tx_desc_cache_size_set)
    rx_write_delay = _swig_property(_param_IGbE.IGbEParams_rx_write_delay_get, _param_IGbE.IGbEParams_rx_write_delay_set)
    rx_desc_cache_size = _swig_property(_param_IGbE.IGbEParams_rx_desc_cache_size_get, _param_IGbE.IGbEParams_rx_desc_cache_size_set)
    rx_fifo_size = _swig_property(_param_IGbE.IGbEParams_rx_fifo_size_get, _param_IGbE.IGbEParams_rx_fifo_size_set)
    wb_delay = _swig_property(_param_IGbE.IGbEParams_wb_delay_get, _param_IGbE.IGbEParams_wb_delay_set)
    tx_read_delay = _swig_property(_param_IGbE.IGbEParams_tx_read_delay_get, _param_IGbE.IGbEParams_tx_read_delay_set)
    phy_epid = _swig_property(_param_IGbE.IGbEParams_phy_epid_get, _param_IGbE.IGbEParams_phy_epid_set)
    fetch_comp_delay = _swig_property(_param_IGbE.IGbEParams_fetch_comp_delay_get, _param_IGbE.IGbEParams_fetch_comp_delay_set)
    wb_comp_delay = _swig_property(_param_IGbE.IGbEParams_wb_comp_delay_get, _param_IGbE.IGbEParams_wb_comp_delay_set)
    def __init__(self): 
        this = _param_IGbE.new_IGbEParams()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _param_IGbE.delete_IGbEParams
    __del__ = lambda self : None;
IGbEParams_swigregister = _param_IGbE.IGbEParams_swigregister
IGbEParams_swigregister(IGbEParams)



