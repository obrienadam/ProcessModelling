#include <fstream>

#include "Utilities.h"
#include "BlockGraphicsItem.h"
#include "ConnectorGraphicsPathItem.h"

void saveSceneToXmlFile(const std::string &filename,
                        const std::vector<BlockGraphicsItem *> &blocks,
                        const std::vector<ConnectorGraphicsPathItem *> &connectors)
{
    std::ofstream fout(filename.c_str());

    fout.close();
}
