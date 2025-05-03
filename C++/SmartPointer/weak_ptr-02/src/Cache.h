#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>

struct Resource
{
	using id_type = int;
	id_type id;

  Resource(id_type id) : id(id) {}

	void reset() { }
};

template <auto Capacity>
class Cache
{
	using clock = std::chrono::system_clock;
	using internal_data = std::vector<std::pair<decltype(std::chrono::system_clock::now()), std::shared_ptr<Resource>>> ;

	public:
		void add(Resource *p);
		bool full() const;
		std::weak_ptr<Resource> obtain(Resource::id_type id);		

	private:
		void expungeOne();
		
		// a cache of capacity Capacity that keeps the most recently used Resource Objects				
		internal_data resources;
};

template <auto Capacity>
void Cache<Capacity>::add(Resource *p)
{
	const auto t = clock::now();
	if (full()) {
		expungeOne();
	}

	resources.emplace_back(t, std::shared_ptr<Resource>{p}); 
}

template <auto Capacity>
bool Cache<Capacity>::full() const
{
	return resources.size() == Capacity;
}

template <auto Capacity>
std::weak_ptr<Resource> Cache<Capacity>::obtain(Resource::id_type id)
{
	const auto t = clock::now();
	auto p = std::find_if(
		begin(resources),
		end(resources),
		[id](auto &&p) { return p.second->id == id; }
	);

	if (p == end(resources)) {
		return {};
	}

	p->first = t;

	return p->second; // make weak_ptr from shared_ptr
}

template <auto Capacity>
void Cache<Capacity>::expungeOne()
{
	auto p = std::min_element(
		begin(resources), 
		end(resources), 
		[](auto &&a, auto &&b) { return a.first < b.first; }
	);

	assert(p != end(resources));
	p->second.reset(); // relingquish ownership
	resources.erase(p);	
}

