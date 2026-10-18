from debug_metrics22 import app_metrics as prior,poll_wrapper,sample_call
from source_budget23 import install


def app_metrics(i,dbg,tick,hooks):
    metrics=prior(i,dbg,tick,hooks)
    metrics['source_budget']=install(i,tick,metrics)
    return metrics
