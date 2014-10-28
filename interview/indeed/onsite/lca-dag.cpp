// Given a DAG similar to a git history, return a list of commits that
// are ordered by the distance to a given commit.
//
// e.g.,
// 0 -- 1 -- 2 -- 3 -- 4 -- 5
//       \___6 __ 7 __ /
//                 \__8
//
// from 5, will be: 5, 4, 3, 7, 2, 6, 1
// Essentially just a BFS
// 
// Then a harder problem: find the closest common ancestor commit of two nodes,
// e.g., given 5 and 8, 7 should be returned (1 is further away).