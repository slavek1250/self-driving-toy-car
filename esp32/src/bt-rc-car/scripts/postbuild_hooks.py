Import("env")
import shutil

def deploy_bin(source, target, env):
    src_bin_path = target[0].get_abspath()
    bin_name = target[0].name
    dest_bin_path = f"bin/{bin_name}"
    shutil.copyfile(src_bin_path, dest_bin_path)

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", deploy_bin)
