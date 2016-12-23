#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>

class BlockGraphicsItem;
class ConnectorGraphicsPathItem;

void saveSceneToXmlFile(const std::string& filename,
                        const std::vector<BlockGraphicsItem*>& blocks,
                        const std::vector<ConnectorGraphicsPathItem*>& connectors);

#endif // UTILITIES_H
