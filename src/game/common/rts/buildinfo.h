/**
 * @file
 *
 * @author OmniBlade
 *
 * @brief Class for managing build information.
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#include "always.h"
#include "asciistring.h"
#include "coord.h"
#include "datachunk.h"
#include "gametype.h"
#include "mempoolobj.h"
#include "snapshot.h"

class RenderObjClass;
class Shadow;

class BuildListInfo : public MemoryPoolObject, public SnapShot
{
    IMPLEMENT_POOL(BuildListInfo);

    enum
    {
        UNLIMITED_REBUILDS = -1,
    };

protected:
    virtual ~BuildListInfo() override;

public:
    BuildListInfo();

    // Snapshot interface methods.
    virtual void CRC_Snapshot(Xfer *xfer) override {}
    virtual void Xfer_Snapshot(Xfer *xfer) override;
    virtual void Load_Post_Process() override {}

    BuildListInfo &operator=(const BuildListInfo &that);

    BuildListInfo *Get_Next() { return m_nextBuildList; }
    void Set_Next(BuildListInfo *next) { m_nextBuildList = next; }
    void Set_Building_Name(Utf8String name) { m_buildingName = name; }
    void Set_Template_Name(Utf8String name) { m_templateName = name; }
    void Set_Location(const Coord3D &location) { m_location = location; }
    void Set_Angle(float angle) { m_angle = angle; }
    void Set_Intially_Built(bool built) { m_isInitiallyBuilt = built; }
    void Set_Object_ID(ObjectID id) { m_objectID = id; }
    void Set_Num_Rebuilds(unsigned int num) { m_numRebuilds = num; }
    void Set_Unk4() { m_unkbool4 = true; }
    void Parse_Data_Chunk(DataChunkInput &input, DataChunkInfo *info);

private:
    Utf8String m_buildingName;
    Utf8String m_templateName;
    Coord3D m_location;
    Coord2D m_rallyPointOffset;
    float m_angle;
    bool m_isInitiallyBuilt;
    unsigned int m_numRebuilds;
    BuildListInfo *m_nextBuildList;
    Utf8String m_script;
    int m_health;
    bool m_whiner;
    bool m_repairable;
    bool m_sellable;
    bool m_autoBuild;
    RenderObjClass *m_renderObj;
    Shadow *m_shadowObj;
    bool m_selected;
    ObjectID m_objectID;
    unsigned int m_objectTimestamp;
    bool m_underConstruction;
    int m_unkArray[10];
    bool m_unkbool3;
    int m_unkint1;
    int m_unkint2;
    bool m_unkbool4;
};