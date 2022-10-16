#include<boost/program_options.hpp>
#include<boost/filesystem.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

class OptionsParcer{
public:
OptionsParcer(int argc, char** argv){
    po::options_description desc{"Options"};
    desc.add_options()
    ("directories,d",po::value<std::vector<fs::path>>(),"Directories for scanning")
    ("exclude,e",po::value<std::vector<fs::path>>(),"Exclude directories for scanning")
    ("level,l",po::value<size_t>()->default_value(0),"Scanning level. 0 level value - is default")
    ("size,s",po::value<size_t>(),"Minimum size of files for scanning")
    ("masks,m",po::value<std::vector<std::string>>(),"Masks filenames for scanning")
    ("block-size,b",po::value<size_t>(),"Block sizes for hash algorithms")
    ("hash-algorithm,h",po::value<std::string>(),"Hash algorithm for scanning - md5 or crc32");

    po::store(po::parse_command_line(argc,argv,desc),vm);
    vm["directories"].as<std::string>();
}
private:
po::variables_map vm;
};