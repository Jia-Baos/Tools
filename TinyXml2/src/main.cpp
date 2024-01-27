#include <iostream>
#include <string>
#include "tinyxml2.h"

void GetEleValue(tinyxml2::XMLElement *element)
{
    for (tinyxml2::XMLElement *currentele = element->FirstChildElement();
         currentele; currentele = currentele->NextSiblingElement())
    {
        tinyxml2::XMLElement *tmpele = currentele;
        if (currentele->GetText() != NULL)
        {
            std::cout << currentele->Name() << ":"
                      << currentele->GetText() << std::endl;
        }

        if (!tmpele->NoChildren())
        {
            GetEleValue(tmpele);
        }
    }
}

int main(int argc, char *argv[])
{
    std::cout << "------Parse the xml file------" << std::endl;
    const std::string xml_path = "D:/Code-VSCode/TinyXml2/01_missing_hole_01.xml";

    tinyxml2::XMLDocument xml;
    xml.LoadFile(xml_path.c_str());

    tinyxml2::XMLElement *root_element = xml.RootElement();
    if (root_element == nullptr)
    {
        return xml.ErrorID();
    }

    GetEleValue(root_element);

    return 0;
}