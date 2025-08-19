import java.util.HashMap;

public class Redis<K, V> {
    private HashMap<K, V> map;
    private long ttl;

    public Redis(K k, V v, long ttl) {
        if (ttl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.map = new HashMap<>();
        this.map.put(k, v);
        this.ttl = ttl;
    }

    //getter and setter
    public K getKey() { return map.keySet().iterator().next(); }
    public V getVal(long elapsedSeconds) throws TtlExpiredException {
        getRemainingTtl(elapsedSeconds);
        if (ttl < 0) {
            throw new TtlExpiredException(getKey() + " expired");
        }
        return map.get(getKey());
    }

    public void setKey(K k) { 
        V value = map.get(getKey());
        map.clear();
        map.put(k, value);
    }
    public void setVal(V v) {
        K key = getKey();
        map.replace(key, v);
    }

    //ttl management
    public long getRemainingTtl(long elapsedSeconds) {
        ttl -= elapsedSeconds;
        return ttl < 0 ? 0 : ttl;
    }
    public void refresh(long newTtl) throws InvalidTtlException {
        if (newTtl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.ttl = newTtl;
    }

    //object comparison
    public boolean isEqual(Redis<?, ?> c) { return this.getKey().equals(c.getKey()) && this.getVal(0).equals(c.getVal(0)); }
    public int nearEQ(Redis<?, ?> c) {
        if (isEqual(c)) return 3;
        else if (this.getVal(0).equals(c.getVal(0))) return 2;
        else if (this.getKey().equals(c.getKey())) return 1;
        return 0;
    }

}