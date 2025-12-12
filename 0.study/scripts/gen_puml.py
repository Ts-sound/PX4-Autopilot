import argparse, os, glob, json, platform, logging
from pathlib import Path

# logging.basicConfig(level=logging.DEBUG ,format="[%(levelname)-s|%(asctime)s|%(filename)s] %(funcName)s:%(lineno)d %(message)s")
logging.basicConfig(
    level=logging.DEBUG,
    format="[%(levelname)s|%(filename)s] [%(funcName)s:%(lineno)d] %(message)s",
)


workpath = str(Path(__file__).resolve().parent.parent.parent)
logging.debug(f"workpath: {workpath}")


g_plantuml_jar = "/opt/tong/dotfiles/vscode/assets/plantuml-1.2025.4.jar"


def gen_puml(input_files, output_file):
    """
    Generate PlantUML file from C++ header file.
    """
    logging.debug(f"input_files: {input_files}")
    logging.debug(f"output_file: {output_file}")

    cmd = "hpp2plantuml "
    for i in input_files:
        cmd += f" -i {i} "
    cmd += f" -o {output_file} "

    logging.debug(f"cmd: {cmd}")
    ret = os.system(cmd)

    cmd = "java -jar " + g_plantuml_jar + " -tsvg -o " + str(Path(output_file).resolve().parent) + "  " + output_file
    logging.debug(f"cmd: {cmd}")
    ret |= os.system(cmd)

    if ret != 0:
        logging.error(f"Command failed with return code {ret}.")
        return False
    logging.debug(f"Command executed successfully.")

    return True


def gen_workqueue():
    ifile_path = workpath + "/platforms/common/include/px4_platform_common/px4_work_queue"
    input_files = glob.glob(ifile_path + "/*.hpp")
    output_file = workpath + "/0.study/01.doc/assets/px4_workqueue.puml"
    gen_puml(input_files, output_file)
    return


def gen_uORB():
    ifile_path = workpath + "/platforms/common/uORB"
    input_files = glob.glob(ifile_path + "/*.hpp")
    output_file = workpath + "/0.study/01.doc/assets/px4_uORB.puml"
    gen_puml(input_files, output_file)
    return


if __name__ == "__main__":
    # parser = argparse.ArgumentParser(description="Generate PlantUML diagrams from C++ header files.")
    # parser.add_argument(
    #     "--workqueue",
    #     action="store_true",
    #     help="Generate PlantUML for PX4 work queue.",
    # )

    # args = parser.parse_args()

    # if args.workqueue:

    gen_workqueue()
    gen_uORB()
