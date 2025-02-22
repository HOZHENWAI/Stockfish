/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2024 The Stockfish developers (see AUTHORS file)

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EVALUATE_H_INCLUDED
#define EVALUATE_H_INCLUDED

#include <string>
#include <unordered_map>

#include "types.h"

namespace Stockfish {

class Position;

namespace Eval {

std::string trace(Position& pos);

int   simple_eval(const Position& pos, Color c);
Value evaluate(const Position& pos);

// The default net name MUST follow the format nn-[SHA256 first 12 digits].nnue
// for the build process (profile-build and fishtest) to work. Do not change the
// name of the macro, as it is used in the Makefile.
#define EvalFileDefaultNameBig "nn-baff1edbea57.nnue"
#define EvalFileDefaultNameSmall "nn-baff1ede1f90.nnue"

namespace NNUE {

enum NetSize : int;

void init();
void verify();

}  // namespace NNUE

struct EvalFile {
    std::string option_name;
    std::string default_name;
    std::string selected_name;
};

extern std::unordered_map<NNUE::NetSize, EvalFile> EvalFiles;

}  // namespace Eval

}  // namespace Stockfish

#endif  // #ifndef EVALUATE_H_INCLUDED
