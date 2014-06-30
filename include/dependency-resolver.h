/*
 * %injeqt copyright begin%
 * Copyright 2014 Rafał Malinowski (rafal.przemyslaw.malinowski@gmail.com)
 * %injeqt copyright end%
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once

#include "injeqt-global.h"

#include <map>
#include <vector>

class QMetaObject;
class QObject;

namespace injeqt { namespace v1 {

class dependency;

class dependency_resolver final
{

public:
	const std::map<const QMetaObject *, dependency> resolve_dependencies(
		QObject &object,
		const std::map<const QMetaObject *, dependency> &to_resolve,
		const std::vector<QObject *> &dependencies) const;
	bool resolve_dependency(
		QObject &object,
		const QMetaObject *type,
		const dependency &to_resolve,
		const std::vector<QObject *> &dependencies) const;

};

}}