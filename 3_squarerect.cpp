bool am_i_square(int N, int Q){
  bool hit = false;
  int fi = -1, fj = -1;
  
  for (int i = 1; i <= 4; i++){
      for (int j = 1; j <= 4; j++){
          if (inside_shape(i * 20, j * 20)){
              hit = true;
              fi = i, fj = j;
              break;
          }
      }
      if (hit) break;
  }
  
  int low, high, mid;
  int l_bound_x, pivot_x, u_bound_x, l_bound_y, pivot_y, u_bound_y, dist_x;
  if (hit){
      l_bound_x = fi * 20; // lower bound to x
      pivot_x = fi * 20; // pivot to x
      u_bound_x = fi * 20; // upper bound to x
  
      l_bound_y = fj * 20; // lower bound to y
      pivot_y = fj * 20; // pivot to y
      u_bound_y = fj * 20; // upper bound to y
  
      // Find lower bound to x
      low = (fi - 1) * 20 + 1, high = fi * 20 - 1;
      while (low <= high){
          mid = (low + high) / 2;
          if (inside_shape(mid, pivot_y)){
              l_bound_x = mid;
              high = mid - 1;
          } else low = mid + 1;
      }
  
      // Find lower bound to y.
      low = (fj - 1) * 20 + 1, high = fj * 20 - 1;
      while (low <= high){
          mid = (low + high) / 2;
          if (inside_shape(pivot_x, mid)){
              l_bound_y = mid;
              high = mid - 1;
          } else low = mid + 1;
      }
  
      // Find upper bound to x.
      low = fi * 20 + 1, high = N;
      while (low <= high){
          mid = (low + high) / 2;
          if (inside_shape(mid, pivot_y)){
              u_bound_x = mid;
              low = mid + 1;
          } else high = mid - 1;
      }
  
  
      // Find dist.
      dist_x = u_bound_x - l_bound_x;
      u_bound_y = l_bound_y + dist_x;
      if (u_bound_y > N) return false;
      if (!inside_shape(pivot_x, u_bound_y)) return false;
      if (u_bound_y < N && inside_shape(pivot_x, u_bound_y + 1)) return false;
      return true;
  }
  
  hit = false;
  for (int j = 1; j <= 4; j++){
      if (inside_shape(N, j * 20)){
          l_bound_y = j * 20;
          low = (j - 1) * 20 + 1, high = j * 20 - 1;
          while (low <= high){
              mid = (low + high) / 2;
              if (inside_shape(N, mid)){
                  l_bound_y = mid;
                  high = mid - 1;
              } else low = mid + 1;
          }
          u_bound_y = 19 + l_bound_y;
          if (u_bound_y > N) return false;
          if (!inside_shape(N, u_bound_y)) return false;
          if (u_bound_y + 1 <= N && inside_shape(N, u_bound_y + 1)) return false;
          return true;
      }
  }
  
  for (int i = 1; i <= 4 && !hit; i++){
      if (inside_shape(i * 20, N)){
          l_bound_x = i * 20;
          low = (i - 1) * 20 + 1, high = i * 20 - 1;
          while (low <= high){
              mid = (low + high) / 2;
              if (inside_shape(mid, N)){
                  l_bound_x = mid;
                  high = mid - 1;
              } else low = mid + 1;
          }
          u_bound_x = l_bound_x + 19;
          if (u_bound_x > N) return false;
          if (!inside_shape(u_bound_x, N)) return false;
          if (u_bound_x + 1 <= N && inside_shape(u_bound_x + 1, N)) return false;
          return true;
      }
  }
  
  l_bound_x = (5 - 1) * 20 + 1, u_bound_x = N;
  l_bound_y = (5 - 1) * 20 + 1, u_bound_y = N;
  if (!inside_shape(u_bound_x, u_bound_y)) return false;
  if (!inside_shape(l_bound_x, u_bound_y)) return false;
  if (l_bound_x - 1 > 0 && inside_shape(l_bound_x - 1, u_bound_y)) return false;
  if (!inside_shape(u_bound_x, l_bound_y)) return false;
  if (l_bound_y - 1 > 0 && inside_shape(u_bound_x, l_bound_y - 1)) return false;
  return true;
}
