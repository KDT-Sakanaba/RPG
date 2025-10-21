#pragma once
#include<memory>
#include<vector>
#include<stack>

template<typename T>
class ObjectPool;

template<typename T>
class PoolHandle {
	// �t�����h�Ɏw�肳�ꂽ�N���X�̓v���C�x�[�g��v���e�N�g�ɃA�N�Z�X���𓾂邱�Ƃ��ł���
	friend class ObjectPool<T>;
	// �ÖٓI�Ȍ^�ϊ���h�~���邽�߂̂���
	explicit PoolHandle(T* obj, ObjectPool<T>* pool)
		:obj_(obj), pool_(pool) {
	}

public:
	// �R�s�[���ł��Ȃ�����
	PoolHandle(const PoolHandle&) = delete;
	// ���[�u�ł���悤�ɂ���
	PoolHandle(PoolHandle&& other)noexcept
		:obj_(other.obj), pool_(other.pool) {
		other.obj_ = nullptr;
		other.pool_ = nullptr;
	}
	// �f�X�g���N�^�[�Ŏ����ϊ�
	~PoolHandle() {
		if (obj_ && pool_) {
			pool_->Release(obj_);
		}
	}
	// �A�N�Z�X���Z�q
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