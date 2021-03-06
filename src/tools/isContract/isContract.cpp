/*-------------------------------------------------------------------------------------------
 * QuickBlocks - Decentralized, useful, and detailed data from Ethereum blockchains
 * Copyright (c) 2018 Great Hill Corporation (http://quickblocks.io)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
#include "etherlib.h"
#include "options.h"

//--------------------------------------------------------------
int main(int argc, const char *argv[]) {

    etherlib_init();

    // Parse command line, allowing for command files
    COptions options;
    if (!options.prepareArguments(argc, argv))
        return 0;

    while (!options.commandList.empty()) {
        string_q command = nextTokenClear(options.commandList, '\n');
        if (!options.parseArguments(command))
            return 0;

        for (uint64_t i = 0 ; i < options.nAddrs ; i++) {
            string_q code1 = getCode(options.addrs[i]);
            bool hasCode = code1.length() > 2;

            if (options.diff) {
                string_q code2 = getCode(options.addrs[i+1]);
                cout << "Code at address '" << options.addrs[i] << ") and (" << "(" << options.addrs[i+1] + ") are "
                        << (code1 == code2 ? "identical" : "different") << "\n";
                break;

            } else if (options.showBytes) {

                cout << "Code at address: " << options.addrs[i] << ":\n";
                cout << code1 << "\n";

            } else if (options.asData) {
                cout << options.addrs[i] << "\t" << (hasCode ? "true" : "false") << "\n";

            } else {
                cout << "isContract(" << options.addrs[i] << "): " << (hasCode ? "true" : "false") << "\n";
                if (verbose)
                    cout << code1 << "\n";

            }
        }
    }
    return 0;
}
