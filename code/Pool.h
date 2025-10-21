#pragma once
#include<memory>
#include<vector>
#include<stack>

template<typename T>
class ObjectPool;

template<typename T>
class PoolHandle {
	// フレンドに指定されたクラスはプライベートやプロテクトにアクセス権を得ることができる
	friend class ObjectPool<T>;
	// 暗黙的な型変換を防止するためのもの
	explicit PoolHandle(T* obj, ObjectPool<T>* pool)
		:obj_(obj), pool_(pool) {
	}

public:
	// コピーをできなくする
	PoolHandle(const PoolHandle&) = delete;
	// ムーブできるようにする
	PoolHandle(PoolHandle&& other)noexcept
		:obj_(other.obj), pool_(other.pool) {
		other.obj_ = nullptr;
		other.pool_ = nullptr;
	}
	// デストラクターで自動変換
	~PoolHandle() {
		if (obj_ && pool_) {
			pool_->Release(obj_);
		}
	}
	// アクセス演算子
	T* operator ->() { return obj_; }
	T& operator* () { return *obj_; }

private:
	T* obj_;
	ObjectPool<T>* pool_;
};

template<typename T>
class ObjectPool {
	friend class PoolHandle<T>;

public:
	explicit ObjectPool(size_t capacity) {
		objects_.reserve(capacity);
		for (size_t i = 0; i < capacity; ++i) {
			objects_.emplace_back(std::make_unique<T>());
			free_.push(objects_.back().get());
		}
	}
	PoolHandle<T> Acquire() {
		if (free_.empty()) throw std::runtime_error("empty");
		T* obj = free_.top();
		free_.pop();
		return PoolHandle<T>(obj, this);
	}

private:
	void Release(T* obj) { free_.push(obj); }
	std::vector<std::unique_ptr<T>> objects_;
	std::stack<T*> free_;
};