/* This file is part of the KDE project
   Copyright (C) 1999 David Faure <faure@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef KBUILD_SERVICE_TYPE_FACTORY_H
#define KBUILD_SERVICE_TYPE_FACTORY_H

#include <kservicetypefactory_p.h>
#include <QtCore/QStringList>

/**
 * Service-type factory for building ksycoca
 * @internal
 */
class KBuildServiceTypeFactory : public KServiceTypeFactory
{
public:
    /**
     * Create factory
     */
    KBuildServiceTypeFactory(KSycoca *db);

    virtual ~KBuildServiceTypeFactory();

    /**
     * Find a service type in the database file
     * @return a pointer to the servicetype in the memory dict (don't free!)
     */
    KServiceType::Ptr findServiceTypeByName(const QString &_name) Q_DECL_OVERRIDE;

    /**
     * Construct a KServiceType from a config file.
     */
    KSycocaEntry *createEntry(const QString &file) const Q_DECL_OVERRIDE;

    KServiceType *createEntry(int) const Q_DECL_OVERRIDE
    {
        assert(0);
        return 0L;
    }

    /**
     * Add entry
     */
    void addEntry(const KSycocaEntry::Ptr &newEntry) Q_DECL_OVERRIDE;

    /**
     * Write out service type specific index files.
     */
    void save(QDataStream &str) Q_DECL_OVERRIDE;

    /**
     * Write out header information
     *
     * Don't forget to call the parent first when you override
     * this function.
     */
    void saveHeader(QDataStream &str) Q_DECL_OVERRIDE;
};

#endif