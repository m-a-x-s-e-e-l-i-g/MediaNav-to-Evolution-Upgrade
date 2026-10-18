"""Compact GPS and empty UI output; retain native actions and five-second RAM."""
from gps_probe24 import build as gps_build
from navigation_probe26 import extend as previous


def extend(i,resolver,backend):
    return previous(i,resolver,backend,safe_cache=True,compact=True)


def build(raw,pin):
    return gps_build(raw,pin,extend,compact=True)
