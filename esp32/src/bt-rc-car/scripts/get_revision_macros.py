import subprocess
from pathlib import Path
from revision import create_revision_str

revision_str = create_revision_str()
print(f"'-DFW_REV=\"{revision_str}\"'")

# print("'-DCORE_DEBUG_LEVEL=5'")
# print("'-DAC_DEBUG'")
