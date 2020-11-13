#include <stdint.h>
#include <stddef.h>
#include <string>
#include <formatstring.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    std::string dataStr = "";

    for(int i = 0; i < size; i++){
        dataStr += data[i];
    }

    newsbeuter::fmtstr_formatter formatter = {};
    
    formatter.do_format(dataStr, 2);

    return 0;
}
