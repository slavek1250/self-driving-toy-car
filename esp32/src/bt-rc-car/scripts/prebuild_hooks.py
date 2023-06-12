Import("env")
from revision import create_revision_str

revision_str = create_revision_str()
env.Replace(PROGNAME=f"bt-rc-car-v{revision_str}")
