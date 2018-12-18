from conans import ConanFile
from glob import glob

class LunaProto(ConanFile):
    name = "lunaProto"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    requires = "flatbuffers/1.10.0@google/stable"
    exports_sources = "*.fbs"

    def build(self):
        for file in glob("*.fbs"):
            self.run("flatc --cpp " + file, run_environment = True)

    def package(self):
        self.copy("*.h", dst="include")
    
    def package_id(self):
        self.info.header_only()
