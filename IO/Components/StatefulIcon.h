//////////////////////////////////////////////////////////////////////////////////
//	This file is part of the continued Journey MMORPG client					//
//	Copyright (C) 2015-2019  Daniel Allendorf, Ryan Payton						//
//																				//
//	This program is free software: you can redistribute it and/or modify		//
//	it under the terms of the GNU Affero General Public License as published by	//
//	the Free Software Foundation, either version 3 of the License, or			//
//	(at your option) any later version.											//
//																				//
//	This program is distributed in the hope that it will be useful,				//
//	but WITHOUT ANY WARRANTY; without even the implied warranty of				//
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the				//
//	GNU Affero General Public License for more details.							//
//																				//
//	You should have received a copy of the GNU Affero General Public License	//
//	along with this program.  If not, see <https://www.gnu.org/licenses/>.		//
//////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Icon.h"

#include "../Graphics/Texture.h"

namespace ms
{
	class StatefulIcon : public Icon
	{
	public:
		class Type : public Icon::Type
		{
		public:
			virtual ~Type() {}

			virtual void set_state(Icon::State state) = 0;
		};

		class NullType : public Type
		{
			void drop_on_stage() const override {}
			void drop_on_equips(Equipslot::Id) const override {}
			bool drop_on_items(InventoryType::Id, Equipslot::Id, int16_t, bool) const override { return true; }
			void drop_on_bindings(Point<int16_t> cursorposition, bool remove) const override {}
			void set_count(int16_t) override {}
			void set_state(Icon::State state) override {};
		};

		StatefulIcon(std::unique_ptr<Type> type, Texture normal_tx, Texture disabled_tx, Texture mouseover_tx);
		StatefulIcon();

		Texture get_texture() const override;

		void set_state(Icon::State state);
	private:
		Icon::State state;
	};
}
